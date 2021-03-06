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
#include "dogen/formatters/types/file_settings.hpp"

namespace dogen {
namespace formatters {

file_settings::file_settings(file_settings&& rhs)
    : copyright_notices_(std::move(rhs.copyright_notices_)),
      licence_name_(std::move(rhs.licence_name_)),
      modeline_group_name_(std::move(rhs.modeline_group_name_)),
      generate_preamble_(std::move(rhs.generate_preamble_)),
      marker_add_date_time_(std::move(rhs.marker_add_date_time_)),
      marker_add_warning_(std::move(rhs.marker_add_warning_)),
      marker_message_(std::move(rhs.marker_message_)) { }

file_settings::file_settings(
    const std::list<std::string>& copyright_notices,
    const std::string& licence_name,
    const std::string& modeline_group_name,
    const boost::optional<bool>& generate_preamble,
    const boost::optional<bool>& marker_add_date_time,
    const boost::optional<bool>& marker_add_warning,
    const std::string& marker_message)
    : copyright_notices_(copyright_notices),
      licence_name_(licence_name),
      modeline_group_name_(modeline_group_name),
      generate_preamble_(generate_preamble),
      marker_add_date_time_(marker_add_date_time),
      marker_add_warning_(marker_add_warning),
      marker_message_(marker_message) { }

void file_settings::swap(file_settings& other) noexcept {
    using std::swap;
    swap(copyright_notices_, other.copyright_notices_);
    swap(licence_name_, other.licence_name_);
    swap(modeline_group_name_, other.modeline_group_name_);
    swap(generate_preamble_, other.generate_preamble_);
    swap(marker_add_date_time_, other.marker_add_date_time_);
    swap(marker_add_warning_, other.marker_add_warning_);
    swap(marker_message_, other.marker_message_);
}

bool file_settings::operator==(const file_settings& rhs) const {
    return copyright_notices_ == rhs.copyright_notices_ &&
        licence_name_ == rhs.licence_name_ &&
        modeline_group_name_ == rhs.modeline_group_name_ &&
        generate_preamble_ == rhs.generate_preamble_ &&
        marker_add_date_time_ == rhs.marker_add_date_time_ &&
        marker_add_warning_ == rhs.marker_add_warning_ &&
        marker_message_ == rhs.marker_message_;
}

file_settings& file_settings::operator=(file_settings other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<std::string>& file_settings::copyright_notices() const {
    return copyright_notices_;
}

std::list<std::string>& file_settings::copyright_notices() {
    return copyright_notices_;
}

void file_settings::copyright_notices(const std::list<std::string>& v) {
    copyright_notices_ = v;
}

void file_settings::copyright_notices(const std::list<std::string>&& v) {
    copyright_notices_ = std::move(v);
}

const std::string& file_settings::licence_name() const {
    return licence_name_;
}

std::string& file_settings::licence_name() {
    return licence_name_;
}

void file_settings::licence_name(const std::string& v) {
    licence_name_ = v;
}

void file_settings::licence_name(const std::string&& v) {
    licence_name_ = std::move(v);
}

const std::string& file_settings::modeline_group_name() const {
    return modeline_group_name_;
}

std::string& file_settings::modeline_group_name() {
    return modeline_group_name_;
}

void file_settings::modeline_group_name(const std::string& v) {
    modeline_group_name_ = v;
}

void file_settings::modeline_group_name(const std::string&& v) {
    modeline_group_name_ = std::move(v);
}

const boost::optional<bool>& file_settings::generate_preamble() const {
    return generate_preamble_;
}

boost::optional<bool>& file_settings::generate_preamble() {
    return generate_preamble_;
}

void file_settings::generate_preamble(const boost::optional<bool>& v) {
    generate_preamble_ = v;
}

void file_settings::generate_preamble(const boost::optional<bool>&& v) {
    generate_preamble_ = std::move(v);
}

const boost::optional<bool>& file_settings::marker_add_date_time() const {
    return marker_add_date_time_;
}

boost::optional<bool>& file_settings::marker_add_date_time() {
    return marker_add_date_time_;
}

void file_settings::marker_add_date_time(const boost::optional<bool>& v) {
    marker_add_date_time_ = v;
}

void file_settings::marker_add_date_time(const boost::optional<bool>&& v) {
    marker_add_date_time_ = std::move(v);
}

const boost::optional<bool>& file_settings::marker_add_warning() const {
    return marker_add_warning_;
}

boost::optional<bool>& file_settings::marker_add_warning() {
    return marker_add_warning_;
}

void file_settings::marker_add_warning(const boost::optional<bool>& v) {
    marker_add_warning_ = v;
}

void file_settings::marker_add_warning(const boost::optional<bool>&& v) {
    marker_add_warning_ = std::move(v);
}

const std::string& file_settings::marker_message() const {
    return marker_message_;
}

std::string& file_settings::marker_message() {
    return marker_message_;
}

void file_settings::marker_message(const std::string& v) {
    marker_message_ = v;
}

void file_settings::marker_message(const std::string&& v) {
    marker_message_ = std::move(v);
}

} }
