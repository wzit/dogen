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
#ifndef DOGEN_QUILT_CPP_TYPES_PROPERTIES_PATH_DERIVATIVES_REPOSITORY_FACTORY_HPP
#define DOGEN_QUILT_CPP_TYPES_PROPERTIES_PATH_DERIVATIVES_REPOSITORY_FACTORY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <unordered_map>
#include "dogen/dynamic/types/object.hpp"
#include "dogen/dynamic/types/repository.hpp"
#include "dogen/config/types/cpp_options.hpp"
#include "dogen/yarn/types/model.hpp"
#include "dogen/quilt.cpp/types/settings/path_settings.hpp"
#include "dogen/quilt.cpp/types/formatters/container.hpp"
#include "dogen/quilt.cpp/types/properties/path_derivatives_repository.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace properties {

/**
 * @brief Creates path derivatives repositories.
 */
class path_derivatives_repository_factory {
public:
    /**
     * @brief Create a path derivatives repository.
     */
    path_derivatives_repository make(const config::cpp_options& opts,
        const std::unordered_map<std::string, settings::path_settings>& ps,
        const yarn::model& m) const;
};

} } } }

#endif
