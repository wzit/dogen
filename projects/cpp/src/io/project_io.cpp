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
#include <ostream>
#include "dogen/cpp/io/cmakelists_info_io.hpp"
#include "dogen/cpp/io/odb_options_info_io.hpp"
#include "dogen/cpp/io/project_io.hpp"
#include "dogen/cpp/io/source_file_io.hpp"

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<dogen::cpp::source_file>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace boost {

inline std::ostream& operator<<(std::ostream& s, const boost::optional<dogen::cpp::cmakelists_info>& v) {
    s << "{ " << "\"__type__\": " << "\"boost::optional\"" << ", ";

    if (v)
        s << "\"data\": " << *v;
    else
        s << "\"data\": ""\"<empty>\"";
    s << " }";
    return s;
}

}

namespace dogen {
namespace cpp {

std::ostream& operator<<(std::ostream& s, const project& v) {
    s << " { "
      << "\"__type__\": " << "\"dogen::cpp::project\"" << ", "
      << "\"files\": " << v.files() << ", "
      << "\"odb_options\": " << v.odb_options() << ", "
      << "\"src_cmakelists\": " << v.src_cmakelists() << ", "
      << "\"include_cmakelists\": " << v.include_cmakelists()
      << " }";
    return(s);
}

} }