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
#ifndef DOGEN_QUILT_CPP_TYPES_PROPERTIES_ELEMENT_PROPERTIES_HPP
#define DOGEN_QUILT_CPP_TYPES_PROPERTIES_ELEMENT_PROPERTIES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <boost/optional.hpp>
#include "dogen/formatters/types/file_properties.hpp"
#include "dogen/quilt.cpp/types/properties/aspect_properties.hpp"
#include "dogen/quilt.cpp/types/properties/helper_properties.hpp"
#include "dogen/quilt.cpp/types/properties/formatter_properties.hpp"
#include "dogen/quilt.cpp/serialization/properties/element_properties_fwd_ser.hpp"

namespace dogen {
namespace quilt {
namespace cpp {
namespace properties {

/**
 * @brief All of the computed properties for an element.
 */
class element_properties final {
public:
    element_properties() = default;
    element_properties(const element_properties&) = default;
    ~element_properties() = default;

public:
    element_properties(element_properties&& rhs);

public:
    element_properties(
        const boost::optional<dogen::formatters::file_properties>& file_properties,
        const std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties>& formatter_properties,
        const std::list<dogen::quilt::cpp::properties::helper_properties>& helper_properties,
        const dogen::quilt::cpp::properties::aspect_properties& aspect_properties);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const dogen::quilt::cpp::properties::element_properties& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, dogen::quilt::cpp::properties::element_properties& v, unsigned int version);

public:
    const boost::optional<dogen::formatters::file_properties>& file_properties() const;
    boost::optional<dogen::formatters::file_properties>& file_properties();
    void file_properties(const boost::optional<dogen::formatters::file_properties>& v);
    void file_properties(const boost::optional<dogen::formatters::file_properties>&& v);

    const std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties>& formatter_properties() const;
    std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties>& formatter_properties();
    void formatter_properties(const std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties>& v);
    void formatter_properties(const std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties>&& v);

    const std::list<dogen::quilt::cpp::properties::helper_properties>& helper_properties() const;
    std::list<dogen::quilt::cpp::properties::helper_properties>& helper_properties();
    void helper_properties(const std::list<dogen::quilt::cpp::properties::helper_properties>& v);
    void helper_properties(const std::list<dogen::quilt::cpp::properties::helper_properties>&& v);

    const dogen::quilt::cpp::properties::aspect_properties& aspect_properties() const;
    dogen::quilt::cpp::properties::aspect_properties& aspect_properties();
    void aspect_properties(const dogen::quilt::cpp::properties::aspect_properties& v);
    void aspect_properties(const dogen::quilt::cpp::properties::aspect_properties&& v);

public:
    bool operator==(const element_properties& rhs) const;
    bool operator!=(const element_properties& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(element_properties& other) noexcept;
    element_properties& operator=(element_properties other);

private:
    boost::optional<dogen::formatters::file_properties> file_properties_;
    std::unordered_map<std::string, dogen::quilt::cpp::properties::formatter_properties> formatter_properties_;
    std::list<dogen::quilt::cpp::properties::helper_properties> helper_properties_;
    dogen::quilt::cpp::properties::aspect_properties aspect_properties_;
};

} } } }

namespace std {

template<>
inline void swap(
    dogen::quilt::cpp::properties::element_properties& lhs,
    dogen::quilt::cpp::properties::element_properties& rhs) {
    lhs.swap(rhs);
}

}

#endif
