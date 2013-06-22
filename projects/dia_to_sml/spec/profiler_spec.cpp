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
#include "dogen/utility/test/asserter.hpp"
#include "dogen/utility/test/logging.hpp"
#include "dogen/dia_to_sml/types/processed_object.hpp"
#include "dogen/dia_to_sml/types/profiler.hpp"
#include "dogen/dia_to_sml/types/profiling_error.hpp"
#include "dogen/dia_to_sml/io/profile_io.hpp"
#include "dogen/dia_to_sml/test/mock_processed_object_factory.hpp"
#include "dogen/utility/test/exception_checkers.hpp"

using namespace dogen::dia_to_sml;
using dogen::utility::test::asserter;

namespace  {

const std::string test_module("dia_to_sml");
const std::string test_suite("profiler_spec");
const std::string invalid_stereotype("Invalid value for stereotype");

unsigned int stereotype_count(const profile& p) {
    unsigned int r(0);

    if (p.is_enumeration()) ++r;
    if (p.is_exception()) ++r;
    if (p.is_entity()) ++r;
    if (p.is_value()) ++r;
    if (p.is_service()) ++r;
    if (p.is_non_generatable()) ++r;
    if (p.is_versioned()) ++r;
    if (p.is_keyed()) ++r;
    if (p.is_visitable()) ++r;
    if (p.is_immutable()) ++r;
    if (p.is_fluent()) ++r;
    if (p.is_aggregate_root()) ++r;
    if (p.is_string_table()) ++r;

    return r;
}

unsigned int type_count(const profile& p) {
    unsigned int r(0);

    if (p.is_uml_class()) ++r;
    if (p.is_uml_large_package()) ++r;
    if (p.is_uml_generalization()) ++r;
    if (p.is_uml_association()) ++r;
    if (p.is_uml_note()) ++r;
    if (p.is_uml_message()) ++r;
    if (p.is_uml_realization()) ++r;

    return r;
}

unsigned int total_count(const profile& p) {
    return stereotype_count(p) + type_count(p);
}

bool is_valid_uml_class(const profile& p) {
    return p.is_uml_class() && type_count(p) == 1;
}

}

using dogen::utility::test::contains_checker;
using dogen::dia_to_sml::test::mock_processed_object_factory;

BOOST_AUTO_TEST_SUITE(profiler)

BOOST_AUTO_TEST_CASE(uml_class_with_no_stereotypes_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_class_with_no_stereotypes_transforms_into_expected_profile");

    const auto o(mock_processed_object_factory::build_class());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(o));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_class());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_note_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_note_transforms_into_expected_profile");

    const auto o(mock_processed_object_factory::build_uml_note());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(o));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_note());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_large_package_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_large_package_transforms_into_expected_profile");

    const auto o(mock_processed_object_factory::build_large_package());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(o));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_large_package());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_generalization_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_generalization_transforms_into_expected_profile");

    const auto a(mock_processed_object_factory::build_generalization());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(a[0]));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_generalization());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_association_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_association_transforms_into_expected_profile");

    const auto a(mock_processed_object_factory::build_association());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(a[2]));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_association());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_message_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_message_transforms_into_expected_profile");

    const auto o(mock_processed_object_factory::build_uml_message());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(o));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_message());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(uml_realization_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("uml_realization_transforms_into_expected_profile");

    const auto a(mock_processed_object_factory::build_realization());
    dogen::dia_to_sml::profiler profiler;
    const auto p(profiler.generate(a[0]));

    BOOST_LOG_SEV(lg, debug) << "actual:" << p;
    BOOST_CHECK(p.is_uml_realization());
    BOOST_CHECK(total_count(p) == 1);
}

BOOST_AUTO_TEST_CASE(stereotyped_class_transforms_into_expected_profile) {
    SETUP_TEST_LOG_SOURCE("stereotyped_class_transforms_into_expected_profile");

    std::string s("enumeration");
    auto o(mock_processed_object_factory::build_class(0, s));
    dogen::dia_to_sml::profiler profiler;
    auto p(profiler.generate(o));

    BOOST_LOG_SEV(lg, debug) << "actual 1:" << p;
    BOOST_CHECK(is_valid_uml_class(p));
    BOOST_CHECK(stereotype_count(p) == 1);
    BOOST_CHECK(p.is_enumeration());

    s = "exception, entity";
    o = mock_processed_object_factory::build_class(0, s);
    p = profiler.generate(o);

    BOOST_LOG_SEV(lg, debug) << "actual 2:" << p;
    BOOST_CHECK(is_valid_uml_class(p));
    BOOST_CHECK(stereotype_count(p) == 2);
    BOOST_CHECK(p.is_exception());
    BOOST_CHECK(p.is_entity());

    s = "entity, aggregate root";
    o = mock_processed_object_factory::build_class(0, s);
    p = profiler.generate(o);

    BOOST_LOG_SEV(lg, debug) << "actual 2:" << p;
    BOOST_CHECK(is_valid_uml_class(p));
    BOOST_CHECK(stereotype_count(p) == 2);
    BOOST_CHECK(p.is_aggregate_root());
    BOOST_CHECK(p.is_entity());

    s = "nongeneratable, versioned, keyed, visitable, immutable, fluent";
    o = mock_processed_object_factory::build_class(0, s);
    p = profiler.generate(o);

    BOOST_LOG_SEV(lg, debug) << "actual 3:" << p;
    BOOST_CHECK(is_valid_uml_class(p));
    BOOST_CHECK(stereotype_count(p) == 6);
    BOOST_CHECK(p.is_non_generatable());
    BOOST_CHECK(p.is_versioned());
    BOOST_CHECK(p.is_keyed());
    BOOST_CHECK(p.is_visitable());
    BOOST_CHECK(p.is_immutable());
    BOOST_CHECK(p.is_fluent());
}

BOOST_AUTO_TEST_CASE(invalid_stereotypes_throw) {
    SETUP_TEST_LOG_SOURCE("invalid_stereotypes_throw");

    std::string s("enumerationz");
    auto o(mock_processed_object_factory::build_class(0, s));
    dogen::dia_to_sml::profiler profiler;
    contains_checker<profiling_error> c(invalid_stereotype);
    BOOST_CHECK_EXCEPTION(profiler.generate(o), profiling_error, c);

    s = "enumeration,invalid";
    o = mock_processed_object_factory::build_class(0, s);
    BOOST_CHECK_EXCEPTION(profiler.generate(o), profiling_error, c);

    s = "enumeration|service";
    o = mock_processed_object_factory::build_class(0, s);
    BOOST_CHECK_EXCEPTION(profiler.generate(o), profiling_error, c);

    s = "enumeration service";
    o = mock_processed_object_factory::build_class(0, s);
    BOOST_CHECK_EXCEPTION(profiler.generate(o), profiling_error, c);
}

BOOST_AUTO_TEST_SUITE_END()
