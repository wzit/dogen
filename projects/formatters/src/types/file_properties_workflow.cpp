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
#include "dogen/formatters/types/file_properties_workflow.hpp"

namespace dogen {
namespace formatters {

file_properties_workflow::file_properties_workflow(
    const dynamic::repository& drp,
    const repository& rp)
    : settings_factory_(drp), properties_factory_(rp) { }

file_properties_workflow::file_properties_workflow(
    const dynamic::repository& drp, const repository& rp,
    const dynamic::object& fallback)
    : settings_factory_(drp),
      properties_factory_(rp, settings_factory_.make(fallback)) { }

file_properties file_properties_workflow::
execute(const std::string& modeline_name) const {
    const auto fs = file_settings();
    return properties_factory_.make(modeline_name, fs);
}

file_properties file_properties_workflow::execute(
    const std::string& modeline_name, const dynamic::object& o) const {
    const auto fs(settings_factory_.make(o));
    return properties_factory_.make(modeline_name, fs);
}

} }
