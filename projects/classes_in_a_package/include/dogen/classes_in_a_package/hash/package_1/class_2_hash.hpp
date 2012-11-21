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
#ifndef DOGEN_CLASSES_IN_A_PACKAGE_HASH_PACKAGE_1_CLASS_2_HASH_HPP
#define DOGEN_CLASSES_IN_A_PACKAGE_HASH_PACKAGE_1_CLASS_2_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "dogen/classes_in_a_package/types/package_1/class_2.hpp"

namespace dogen {
namespace classes_in_a_package {
namespace package_1 {

class class_2_hasher {
public:
    static std::size_t hash(const class_2& v);
};

} } }

namespace std {

template<>
class hash<dogen::classes_in_a_package::package_1::class_2> {
public:
    size_t operator()(const dogen::classes_in_a_package::package_1::class_2& v) const {
        return dogen::classes_in_a_package::package_1::class_2_hasher::hash(v);
    }
};

}
#endif
