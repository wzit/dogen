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
#ifndef DOGEN_DYNAMIC_TYPES_NUMBER_HPP
#define DOGEN_DYNAMIC_TYPES_NUMBER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "dogen/dynamic/types/value.hpp"
#include "dogen/dynamic/types/value_visitor.hpp"
#include "dogen/dynamic/serialization/number_fwd_ser.hpp"

namespace dogen {
namespace dynamic {

/**
 * @brief Field can hold numbers.
 */
class number final : public dogen::dynamic::value {
public:
    number(const number&) = default;
    number(number&&) = default;

public:
    number();

    virtual ~number() noexcept { }

public:
    explicit number(const int content);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const dogen::dynamic::number& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, dogen::dynamic::number& v, unsigned int version);

public:
    using value::accept;

    virtual void accept(const value_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(value_visitor& v) const override {
        v.visit(*this);
    }

    virtual void accept(const value_visitor& v) override {
        v.visit(*this);
    }

    virtual void accept(value_visitor& v) override {
        v.visit(*this);
    }

public:
    void to_stream(std::ostream& s) const override;

public:
    int content() const;
    void content(const int v);

public:
    bool operator==(const number& rhs) const;
    bool operator!=(const number& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const dogen::dynamic::value& other) const override;

public:
    void swap(number& other) noexcept;
    number& operator=(number other);

private:
    int content_;
};

} }

namespace std {

template<>
inline void swap(
    dogen::dynamic::number& lhs,
    dogen::dynamic::number& rhs) {
    lhs.swap(rhs);
}

}

#endif
