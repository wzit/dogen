/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <boost/throw_exception.hpp>
#include <boost/algorithm/string.hpp>
#include "dogen/utility/log/logger.hpp"
#include "dogen/yarn/types/name_factory.hpp"
#include "dogen/yarn/types/name_builder.hpp"
#include "dogen/yarn/types/expansion_error.hpp"
#include "dogen/yarn/types/elements_traversal.hpp"
#include "dogen/yarn/types/modules_expander.hpp"

namespace {

using namespace dogen::utility::log;
auto lg(logger_factory("yarn.modules_expander"));

const std::string separator(".");
const std::string missing_module("Could not find module: ");

}

namespace dogen {
namespace yarn {

namespace {

class internal_modules_builder {
private:
    void process(const name& n);

public:
    void operator()(dogen::yarn::module& m) { process(m.name()); }
    void operator()(dogen::yarn::concept& c) { process(c.name()); }
    void operator()(dogen::yarn::primitive& p) { process(p.name()); }
    void operator()(dogen::yarn::enumeration& e) { process(e.name()); }
    void operator()(dogen::yarn::object& o) { process(o.name()); }
    void operator()(dogen::yarn::exception& e) { process(e.name()); }
    void operator()(dogen::yarn::visitor& v) { process(v.name()); }

public:
    const std::unordered_map<std::string, std::list<std::string>>&
    result();

public:
    std::unordered_map<std::string, std::list<std::string>>
        distinct_internal_moduless_;
};

void internal_modules_builder::process(const name& n) {
    auto imp(n.location().internal_modules());
    while (!imp.empty()) {
        const std::string key(boost::join(imp, separator));
        distinct_internal_moduless_.insert(std::make_pair(key, imp));
        imp.pop_back();
    }
}

const std::unordered_map<std::string, std::list<std::string>>&
    internal_modules_builder::result() {
    return distinct_internal_moduless_;
}

class updater {
public:
    updater(intermediate_model& m) : model_(m) { }

private:
    boost::optional<name> containing_module(const name& n);
    void update(element& e);

public:
    void operator()(dogen::yarn::module& m) { update(m); }
    void operator()(dogen::yarn::concept& c) { update(c); }
    void operator()(dogen::yarn::primitive& p) { update(p); }
    void operator()(dogen::yarn::enumeration& e) { update(e); }
    void operator()(dogen::yarn::object& o) { update(o); }
    void operator()(dogen::yarn::exception& e) { update(e); }
    void operator()(dogen::yarn::visitor& v) { update(v); }

public:
    intermediate_model& model_;
};

boost::optional<name> updater::containing_module(const name& n) {
    BOOST_LOG_SEV(lg, debug) << "Finding containing module for: "
                             << n.id();

    const bool in_global_namespace(n.location().model_modules().empty());
    if (in_global_namespace) {
        BOOST_LOG_SEV(lg, debug) << "Type is in global module so, it has"
                                 << " no containing module yet. Type: "
                                 << n.id();
        return boost::optional<name>();
    }

    const bool at_model_level(n.location().internal_modules().empty());
    const auto mn(n.location().model_modules().back());
    if (at_model_level && n.simple() == mn) {
        BOOST_LOG_SEV(lg, debug) << "Type is a model module, so containing "
                                 << "module will be handled later. Type: "
                                 << n.id();
        return boost::optional<name>();
    }

    name_builder b;

    /* we can always take the external modules regardless because these
     * do not contribute to the modules in the model.
     */
     b.external_modules(n.location().external_modules());

    auto imp(n.location().internal_modules());
    if (imp.empty()) {
        /* if there are no internal modules, we must be at the
         * top-level, so take the model name.
         */
        b.simple_name(mn);

        /* the model name may be composite. If so, we need to make
         * sure we add the remaining components.
         */
        if (!n.location().model_modules().empty()) {
            auto remaining_model_modules(n.location().model_modules());
            remaining_model_modules.pop_back();
            b.model_modules(remaining_model_modules);
        }
    } else {
        /* if we are an internal module, we can take the module name
         * and use that as our simple name. We need to add the
         * remaining internal module names to our location.
         */
        b.model_modules(n.location().model_modules());
        b.simple_name(imp.back());
        imp.pop_back();
        b.internal_modules(imp);
    }

    const auto module_n(b.build());
    const auto i(model_.modules().find(module_n.id()));
    if (i != model_.modules().end()) {
        BOOST_LOG_SEV(lg, debug) << "Adding type to module. Type: '"
                                 << n.id()
                                 << "' Module: '" << module_n.id();
        i->second.members().push_back(n);
        return module_n;
    }

    BOOST_LOG_SEV(lg, warn) << "Could not find containing module: "
                            << module_n.id();
    return boost::optional<name>();
}

void updater::update(element& e) {
    e.contained_by(containing_module(e.name()));

    if (!e.contained_by())
        return;

    auto i(model_.modules().find(e.contained_by()->id()));
    if (i == model_.modules().end()) {
        const auto sn(e.contained_by()->simple());
        BOOST_LOG_SEV(lg, error) << missing_module << sn;
        BOOST_THROW_EXCEPTION(expansion_error(missing_module + sn));
    }
}

}

void modules_expander::create_missing_modules(intermediate_model& m) const {
    internal_modules_builder b;
    yarn::elements_traversal(m, b);

    for (const auto& pair : b.result()) {
        yarn::name_factory f;
        const auto& ipp(pair.second);
        const auto n(f.build_module_name(m.name(), ipp));
        const auto i(m.modules().find(n.id()));
        if (i == m.modules().end()) {
            yarn::module mod;
            mod.name(n);
            mod.origin_type(m.origin_type());
            mod.generation_type(m.generation_type());
            m.modules().insert(std::make_pair(n.id(), mod));
        }
    }
}

void modules_expander::expand_containing_module(intermediate_model& m) const {
    updater g(m);
    yarn::elements_traversal(m, g);
}

void modules_expander::expand(intermediate_model& m) const {
    create_missing_modules(m);
    expand_containing_module(m);
}

} }
