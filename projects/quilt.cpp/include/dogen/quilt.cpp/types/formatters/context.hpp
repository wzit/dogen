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
#ifndef DOGEN_QUILT_CPP_TYPES_FORMATTERS_CONTEXT_HPP
#define DOGEN_QUILT_CPP_TYPES_FORMATTERS_CONTEXT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <memory>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "dogen/quilt.cpp/types/settings/element_settings.hpp"
#include "dogen/quilt.cpp/types/settings/streaming_settings_repository.hpp"
#include "dogen/quilt.cpp/types/properties/element_properties.hpp"
#include "dogen/quilt.cpp/types/formatters/helper_formatter_interface.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace formatters {

/**
 * @brief Supplies additional information required for formatting.
 */
class context final {
public:
    context(
        const settings::streaming_settings_repository& ssrp,
        const settings::element_settings& element_settings,
        const properties::element_properties& element_properties,
        const std::unordered_map<std::string, std::unordered_map<std::string,
        std::list<std::shared_ptr<helper_formatter_interface>>>>& helpers);

public:
    const settings::streaming_settings_repository&
    streaming_settings_repository() const;
    const settings::element_settings& element_settings() const;
    const properties::element_properties& element_properties() const;
    const std::unordered_map<
        std::string,
        std::unordered_map<
            std::string,
            std::list<std::shared_ptr<helper_formatter_interface>>>>&
        helpers() const;

private:
    const settings::streaming_settings_repository&
    streaming_settings_repository_;
    const settings::element_settings& element_settings_;
    const properties::element_properties& element_properties_;
    const std::unordered_map<
        std::string,
        std::unordered_map<
            std::string, std::list<
                             std::shared_ptr<helper_formatter_interface>>>>&
    helpers_;
};

} } } }

#endif
