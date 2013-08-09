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
#ifndef DOGEN_CPP_TYPES_ELEMENT_INFO_HPP
#define DOGEN_CPP_TYPES_ELEMENT_INFO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include <string>
#include "dogen/cpp/serialization/element_info_fwd_ser.hpp"

namespace dogen {
namespace cpp {

class element_info final {
public:
    element_info() = default;
    element_info(const element_info&) = default;
    element_info(element_info&&) = default;
    ~element_info() = default;

public:
    element_info(
        const std::string& name,
        const std::string& documentation);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const element_info& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, element_info& v, unsigned int version);

public:
    /**
     * @brief Name of the entity.
     *
     * Must be valid according to the rules for C++ names.
     */
    /**@{*/
    const std::string& name() const;
    std::string& name();
    void name(const std::string& v);
    void name(const std::string&& v);
    /**@}*/

    /**
     * @brief Code comments.
     *
     * These are expected to follow the grammar of the comment processing tools
     * of the programming language in question, e.g. Doxygen for C++, JavaDoc
     * for Java, etc.
     */
    /**@{*/
    const std::string& documentation() const;
    std::string& documentation();
    void documentation(const std::string& v);
    void documentation(const std::string&& v);
    /**@}*/

public:
    bool operator==(const element_info& rhs) const;
    bool operator!=(const element_info& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(element_info& other) noexcept;
    element_info& operator=(element_info other);

private:
    std::string name_;
    std::string documentation_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::cpp::element_info& lhs,
    dogen::cpp::element_info& rhs) {
    lhs.swap(rhs);
}

}

#endif
