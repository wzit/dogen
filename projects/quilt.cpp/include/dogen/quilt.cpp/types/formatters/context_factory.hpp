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
#ifndef DOGEN_QUILT_CPP_TYPES_FORMATTERS_CONTEXT_FACTORY_HPP
#define DOGEN_QUILT_CPP_TYPES_FORMATTERS_CONTEXT_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include "dogen/quilt.cpp/types/workflow_error.hpp"
#include "dogen/quilt.cpp/types/settings/bundle_repository.hpp"
#include "dogen/quilt.cpp/types/properties/element_properties_repository.hpp"
#include "dogen/quilt.cpp/types/formatters/context.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace formatters {

class context_factory {
public:
    context_factory(const settings::bundle_repository& brp,
        const properties::element_properties_repository& fprp,
        const std::unordered_map<
        std::string, std::unordered_map<
        std::string,
        std::shared_ptr<formatter_helper_interface>>>& helpers);

private:
    const properties::element_properties&
    properties_for_id(const std::string& n) const;

    const settings::bundle& bundle_for_id(const std::string& n) const;

public:
    context make(const std::string& id) const;
    context make_empty_context() const;

private:
    static const settings::bundle empty_bundle_;
    static const std::unordered_map<
        std::string,
        std::unordered_map<
            std::string,
            std::shared_ptr<formatter_helper_interface>>> empty_helpers_;
    static const properties::element_properties empty_element_properties_;
    const settings::bundle_repository& bundle_;
    const properties::element_properties_repository& element_properties_;
    const std::unordered_map<
        std::string,
        std::unordered_map<std::string,
                           std::shared_ptr<formatter_helper_interface>>>&
        formatter_helpers_;
};

} } } }

#endif
