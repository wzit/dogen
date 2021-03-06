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
#include "dogen/yarn/types/type_parameters_settings.hpp"

namespace dogen {
namespace yarn {

type_parameters_settings::type_parameters_settings()
    : variable_number_of_parameters_(static_cast<bool>(0)),
      count_(static_cast<unsigned int>(0)),
      always_in_heap_(static_cast<bool>(0)) { }

type_parameters_settings::type_parameters_settings(
    const bool variable_number_of_parameters,
    const unsigned int count,
    const bool always_in_heap)
    : variable_number_of_parameters_(variable_number_of_parameters),
      count_(count),
      always_in_heap_(always_in_heap) { }

void type_parameters_settings::swap(type_parameters_settings& other) noexcept {
    using std::swap;
    swap(variable_number_of_parameters_, other.variable_number_of_parameters_);
    swap(count_, other.count_);
    swap(always_in_heap_, other.always_in_heap_);
}

bool type_parameters_settings::operator==(const type_parameters_settings& rhs) const {
    return variable_number_of_parameters_ == rhs.variable_number_of_parameters_ &&
        count_ == rhs.count_ &&
        always_in_heap_ == rhs.always_in_heap_;
}

type_parameters_settings& type_parameters_settings::operator=(type_parameters_settings other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

bool type_parameters_settings::variable_number_of_parameters() const {
    return variable_number_of_parameters_;
}

void type_parameters_settings::variable_number_of_parameters(const bool v) {
    variable_number_of_parameters_ = v;
}

unsigned int type_parameters_settings::count() const {
    return count_;
}

void type_parameters_settings::count(const unsigned int v) {
    count_ = v;
}

bool type_parameters_settings::always_in_heap() const {
    return always_in_heap_;
}

void type_parameters_settings::always_in_heap(const bool v) {
    always_in_heap_ = v;
}

} }
