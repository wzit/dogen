# -*- mode: cmake; cmake-tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#

#
# macro to create CTest tests for each boost unit tests
#
macro(add_boost_tests test_module)
    foreach(cpp_file ${ARGN})
        file(READ "${cpp_file}" contents)
        string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\(([A-Za-z_0-9]+)\\)"
            found_tests ${contents})

        foreach(hit ${found_tests})
            string(REGEX REPLACE "BOOST_AUTO_TEST_CASE(\\([A-Za-z_0-9]+\\))"
                "\\1" test_name ${hit})
            string(REPLACE "(" "" test_name ${test_name})
            string(REPLACE ")" "" test_name ${test_name})

            string(REPLACE "_tests.cpp" "_tests" test_suite ${cpp_file})
            # string(REPLACE "tests/" "" test_suite ${test_suite})

            set(tests_cmd
                ${stage_bin_dir}/dogen.${test_module}.tests)
            add_test(${test_module}/${test_suite}/${test_name}
                ${CMAKE_COMMAND} -E chdir ${stage_bin_dir}
                ${tests_cmd} --run_test=${test_suite}/${test_name})
        endforeach()
    endforeach()
endmacro()

#
# compiler and linker flags
if (CMAKE_CXX_COMPILER MATCHES ".*clang")
    set(CMAKE_COMPILER_IS_CLANGXX 1)
endif()

if (UNIX)
    check_library_exists(rt clock_gettime "" HAVE_CLOCK_GETTIME)
    if (HAVE_CLOCK_GETTIME)
        message(STATUS "Requires clock_gettime.")
        set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} rt)
    else()
        message(STATUS "Does NOT require clock_gettime.")
    endif()
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    # enable as many warnings as possible
    set(warning_flags "-Wall -Wextra")

    if (CMAKE_COMPILER_IS_GNUCXX)
        # FIXME: causing problems with variants and move constructors.
        set(warning_flags "${warning_flags} -Wno-maybe-uninitialized")
    endif()

    if (CMAKE_COMPILER_IS_CLANGXX)
        # disable mismatched tags as there are STL inconsistencies that
        # make it a bit useless.
        set(warning_flags "${warning_flags} -Wno-mismatched-tags")
    endif()

    # issue all the warnings demanded by strict iso c and iso c++
    set(warning_flags "${warning_flags} -pedantic")

    # treat warnings as errors
    set(warning_flags "${warning_flags} -Werror")

    # do not issue warnings for system headers
    set(warning_flags "${warning_flags} -Wno-system-headers")

    # overloaded virtual function has a different signature
    set(warning_flags "${warning_flags} -Woverloaded-virtual")

    # make string constants const char*
    set(warning_flags "${warning_flags} -Wwrite-strings")

    if(WITH_PROFILING)
        # enable code profiling options
        set(profiling_flags "-fprofile-arcs -ftest-coverage")

        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
            # FIXME: profiling flags appear not to be used during
            # compilation so disable the warning. bit of a hack, for now.
            set(profiling_flags "${profiling_flags} -Qunused-arguments")

            set(profiling_flags "${profiling_flags} --coverage")
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-cfg-checksum")
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-no-function-names-in-data")

            # 407 for gcc 4.7 compatibility of the gcov format.
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-version='407*'")
        endif()
    endif()

    # enable RTTI
    # -fvisibility=hidden
    add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
    if (WIN32)
        set(other_flags "-std=gnu++14")
    else()
        set(other_flags "-std=c++14")
    endif()
    set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
    set(other_flags "${other_flags} -fvisibility=default")

    # set the flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${optimisation_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warning_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${profiling_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")

    # ignore fuzzy link errors
    if (WIN32)
        set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
        set(CMAKE_SHARED_LINKER_FLAGS
            "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
    endif()

elseif(MSVC)
    if (${MSVC_VERSION} GREATER 1399) # 1400+ => VC2005+
        # cannot use incremental rebuild
        string(REPLACE "/Gm" "" CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
        string(REPLACE "/Gm" "" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
        string(REPLACE "/Gm" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
        string(REPLACE "/Gm" "" CMAKE_CXX_FLAGS_RELEASE
            ${CMAKE_CXX_FLAGS_RELEASE})
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

        # workaround for C1128: number of sections exceeded object
        # file format limit.
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    endif()
endif()

# parameters for boost tests
set(boost_test_parameters "")

# user includes
include_directories(
    # generated header files
    ${stage_inc_dir}/

    # real code
    ${CMAKE_SOURCE_DIR}/projects/dia/include
    ${CMAKE_SOURCE_DIR}/projects/quilt/include
    ${CMAKE_SOURCE_DIR}/projects/yarn/include
    ${CMAKE_SOURCE_DIR}/projects/yarn.json/include
    ${CMAKE_SOURCE_DIR}/projects/yarn.dia/include
    ${CMAKE_SOURCE_DIR}/projects/config/include
    ${CMAKE_SOURCE_DIR}/projects/quilt.cpp/include
    ${CMAKE_SOURCE_DIR}/projects/formatters/include
    ${CMAKE_SOURCE_DIR}/projects/utility/include
    ${CMAKE_SOURCE_DIR}/projects/knit/include
    ${CMAKE_SOURCE_DIR}/projects/knitter/include
    ${CMAKE_SOURCE_DIR}/projects/dynamic/include
    ${CMAKE_SOURCE_DIR}/projects/stitch/include
    ${CMAKE_SOURCE_DIR}/projects/stitcher/include
    )

set(COVERALLS_SRC "")

#
# add all other projects
#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dia/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dia/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/quilt/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/quilt/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn.json/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn.json/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn.dia/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yarn.dia/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/config/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/config/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/quilt.cpp/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/quilt.cpp/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/formatters/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/formatters/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utility/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utility/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/knit/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/knit/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/knitter/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/knitter/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dynamic/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stitch/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stitch/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stitcher/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stitcher/tests)

if(WITH_COVERALLS)
    set(COVERAGE_SRCS "${COVERALLS_SRC}")
    coveralls_setup("${COVERAGE_SRCS}" ON "${PROJECT_SOURCE_DIR}/build/cmake")
endif()

# test models
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test_models)
