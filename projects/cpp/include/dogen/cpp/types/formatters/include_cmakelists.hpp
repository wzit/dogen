/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012 Kitanda <info@kitanda.co.uk>
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
#ifndef DOGEN_CPP_TYPES_FORMATTERS_INCLUDE_CMAKELISTS_HPP
#define DOGEN_CPP_TYPES_FORMATTERS_INCLUDE_CMAKELISTS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <string>
#include "dogen/cpp/types/formatters/indenter.hpp"
#include "dogen/cpp/types/cmakelists_view_model.hpp"

namespace dogen {
namespace cpp {
namespace formatters {

class include_cmakelists {
public:
    include_cmakelists() = delete;
    include_cmakelists(const include_cmakelists&) = default;
    ~include_cmakelists() noexcept = default;
    include_cmakelists(include_cmakelists&&) = default;
    include_cmakelists& operator=(const include_cmakelists&) = default;

public:
    include_cmakelists(std::ostream& stream, const bool odb_enabled,
        const std::string odb_folder);

public:
    void format(const cmakelists_view_model& vm);

private:
    std::ostream& stream_;
    indenter indenter_;
    const bool odb_enabled_;
    const std::string odb_folder_;
};

} } }

#endif
