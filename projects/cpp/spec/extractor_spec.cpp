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
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "dogen/utility/test/logging.hpp"
#include "dogen/cpp/types/extractor.hpp"

namespace {

const std::string empty;
const std::string test_module("cpp");
const std::string test_suite("extractor_spec");

}

BOOST_AUTO_TEST_SUITE(extractor)

BOOST_AUTO_TEST_CASE(test) {
    SETUP_TEST_LOG_SOURCE("test");
    // relationships extract_dependency_graph(const sml::pod& p) const;

    BOOST_LOG_SEV(lg, debug) << "zero indent: '";
}

BOOST_AUTO_TEST_SUITE_END()
