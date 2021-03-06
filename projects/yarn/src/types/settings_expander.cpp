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
#include "dogen/yarn/types/type_parameters_settings_factory.hpp"
#include "dogen/yarn/types/generalization_settings_factory.hpp"
#include "dogen/yarn/types/generalization_settings.hpp"
#include "dogen/yarn/types/type_parameters_settings.hpp"
#include "dogen/yarn/types/settings_expander.hpp"

namespace dogen {
namespace yarn {

settings_expander::settings_expander(const dynamic::repository& drp)
    : dynamic_repository_(drp) { }


void settings_expander::expand_type_settings(object& o) const {
    type_parameters_settings_factory f(dynamic_repository_);
    const auto s(f.make(o.extensions()));
    o.type_parameters_settings(s);
}

void settings_expander::expand_generalization_settings(object& o) const {
    generalization_settings_factory f(dynamic_repository_);
    const auto s(f.make(o.extensions()));
    o.generalization_settings(s);
}

void settings_expander::expand(intermediate_model& m) const {
    for (auto& pair : m.objects()) {
        auto& o(pair.second);
        expand_type_settings(o);
        expand_generalization_settings(o);
    }
}

} }
