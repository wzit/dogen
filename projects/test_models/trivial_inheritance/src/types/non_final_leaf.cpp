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
#include <ostream>
#include "dogen/test_models/trivial_inheritance/io/descendant1_io.hpp"
#include "dogen/test_models/trivial_inheritance/types/non_final_leaf.hpp"

namespace dogen {
namespace test_models {
namespace trivial_inheritance {

non_final_leaf::non_final_leaf()
    : prop_0_(static_cast<int>(0)) { }

non_final_leaf::non_final_leaf(const int prop_0)
    : dogen::test_models::trivial_inheritance::descendant1(),
      prop_0_(prop_0) { }

void non_final_leaf::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"dogen::test_models::trivial_inheritance::non_final_leaf\"" << ", "
      << "\"__parent_0__\": ";
    descendant1::to_stream(s);
    s << ", "
      << "\"prop_0\": " << prop_0_
      << " }";
}

void non_final_leaf::swap(non_final_leaf& other) noexcept {
    descendant1::swap(other);

    using std::swap;
    swap(prop_0_, other.prop_0_);
}

bool non_final_leaf::equals(const dogen::test_models::trivial_inheritance::base& other) const {
    const non_final_leaf* const p(dynamic_cast<const non_final_leaf* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool non_final_leaf::operator==(const non_final_leaf& rhs) const {
    return descendant1::compare(rhs) &&
        prop_0_ == rhs.prop_0_;
}

non_final_leaf& non_final_leaf::operator=(non_final_leaf other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int non_final_leaf::prop_0() const {
    return prop_0_;
}

void non_final_leaf::prop_0(const int v) {
    prop_0_ = v;
}

} } }
