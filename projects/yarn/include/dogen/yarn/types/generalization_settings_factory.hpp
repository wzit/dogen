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
#ifndef DOGEN_YARN_TYPES_GENERALIZATION_SETTINGS_FACTORY_HPP
#define DOGEN_YARN_TYPES_GENERALIZATION_SETTINGS_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "dogen/dynamic/types/object.hpp"
#include "dogen/dynamic/types/repository.hpp"
#include "dogen/dynamic/types/field_selector.hpp"
#include "dogen/dynamic/types/field_definition.hpp"
#include "dogen/yarn/types/generalization_settings.hpp"

namespace dogen {
namespace yarn {

class generalization_settings_factory {
public:
    explicit generalization_settings_factory(const dynamic::repository& rp);

private:
    /**
     * @brief All field definitions we require.
     */
    struct field_definitions {
        dynamic::field_definition is_final;
        dynamic::field_definition parent;
    };

    /**
     * @brief Creates all of field definitions.
     */
    field_definitions make_field_definitions(
        const dynamic::repository& rp) const;

public:
    generalization_settings make(const dynamic::object& o) const;

private:
    const field_definitions field_definitions_;
};

} }

#endif
