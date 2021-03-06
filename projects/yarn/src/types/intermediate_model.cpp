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
#include "dogen/yarn/types/intermediate_model.hpp"

namespace dogen {
namespace yarn {

intermediate_model::intermediate_model()
    : origin_type_(static_cast<dogen::yarn::origin_types>(0)),
      generation_type_(static_cast<dogen::yarn::generation_types>(0)),
      is_target_(static_cast<bool>(0)),
      has_generatable_types_(static_cast<bool>(0)) { }

intermediate_model::intermediate_model(
    const dogen::yarn::name& name,
    const dogen::yarn::origin_types origin_type,
    const std::string& original_model_name,
    const dogen::yarn::generation_types generation_type,
    const std::unordered_map<dogen::yarn::name, dogen::yarn::origin_types>& references,
    const std::unordered_set<dogen::yarn::name>& leaves,
    const std::unordered_map<std::string, dogen::yarn::module>& modules,
    const std::unordered_map<std::string, dogen::yarn::concept>& concepts,
    const std::unordered_map<std::string, dogen::yarn::primitive>& primitives,
    const std::unordered_map<std::string, dogen::yarn::enumeration>& enumerations,
    const std::unordered_map<std::string, dogen::yarn::object>& objects,
    const std::unordered_map<std::string, dogen::yarn::exception>& exceptions,
    const std::unordered_map<std::string, dogen::yarn::visitor>& visitors,
    const bool is_target,
    const bool has_generatable_types,
    const dogen::yarn::indices& indices)
    : name_(name),
      origin_type_(origin_type),
      original_model_name_(original_model_name),
      generation_type_(generation_type),
      references_(references),
      leaves_(leaves),
      modules_(modules),
      concepts_(concepts),
      primitives_(primitives),
      enumerations_(enumerations),
      objects_(objects),
      exceptions_(exceptions),
      visitors_(visitors),
      is_target_(is_target),
      has_generatable_types_(has_generatable_types),
      indices_(indices) { }

void intermediate_model::swap(intermediate_model& other) noexcept {
    using std::swap;
    swap(name_, other.name_);
    swap(origin_type_, other.origin_type_);
    swap(original_model_name_, other.original_model_name_);
    swap(generation_type_, other.generation_type_);
    swap(references_, other.references_);
    swap(leaves_, other.leaves_);
    swap(modules_, other.modules_);
    swap(concepts_, other.concepts_);
    swap(primitives_, other.primitives_);
    swap(enumerations_, other.enumerations_);
    swap(objects_, other.objects_);
    swap(exceptions_, other.exceptions_);
    swap(visitors_, other.visitors_);
    swap(is_target_, other.is_target_);
    swap(has_generatable_types_, other.has_generatable_types_);
    swap(indices_, other.indices_);
}

bool intermediate_model::operator==(const intermediate_model& rhs) const {
    return name_ == rhs.name_ &&
        origin_type_ == rhs.origin_type_ &&
        original_model_name_ == rhs.original_model_name_ &&
        generation_type_ == rhs.generation_type_ &&
        references_ == rhs.references_ &&
        leaves_ == rhs.leaves_ &&
        modules_ == rhs.modules_ &&
        concepts_ == rhs.concepts_ &&
        primitives_ == rhs.primitives_ &&
        enumerations_ == rhs.enumerations_ &&
        objects_ == rhs.objects_ &&
        exceptions_ == rhs.exceptions_ &&
        visitors_ == rhs.visitors_ &&
        is_target_ == rhs.is_target_ &&
        has_generatable_types_ == rhs.has_generatable_types_ &&
        indices_ == rhs.indices_;
}

intermediate_model& intermediate_model::operator=(intermediate_model other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const dogen::yarn::name& intermediate_model::name() const {
    return name_;
}

dogen::yarn::name& intermediate_model::name() {
    return name_;
}

void intermediate_model::name(const dogen::yarn::name& v) {
    name_ = v;
}

void intermediate_model::name(const dogen::yarn::name&& v) {
    name_ = std::move(v);
}

dogen::yarn::origin_types intermediate_model::origin_type() const {
    return origin_type_;
}

void intermediate_model::origin_type(const dogen::yarn::origin_types v) {
    origin_type_ = v;
}

const std::string& intermediate_model::original_model_name() const {
    return original_model_name_;
}

std::string& intermediate_model::original_model_name() {
    return original_model_name_;
}

void intermediate_model::original_model_name(const std::string& v) {
    original_model_name_ = v;
}

void intermediate_model::original_model_name(const std::string&& v) {
    original_model_name_ = std::move(v);
}

dogen::yarn::generation_types intermediate_model::generation_type() const {
    return generation_type_;
}

void intermediate_model::generation_type(const dogen::yarn::generation_types v) {
    generation_type_ = v;
}

const std::unordered_map<dogen::yarn::name, dogen::yarn::origin_types>& intermediate_model::references() const {
    return references_;
}

std::unordered_map<dogen::yarn::name, dogen::yarn::origin_types>& intermediate_model::references() {
    return references_;
}

void intermediate_model::references(const std::unordered_map<dogen::yarn::name, dogen::yarn::origin_types>& v) {
    references_ = v;
}

void intermediate_model::references(const std::unordered_map<dogen::yarn::name, dogen::yarn::origin_types>&& v) {
    references_ = std::move(v);
}

const std::unordered_set<dogen::yarn::name>& intermediate_model::leaves() const {
    return leaves_;
}

std::unordered_set<dogen::yarn::name>& intermediate_model::leaves() {
    return leaves_;
}

void intermediate_model::leaves(const std::unordered_set<dogen::yarn::name>& v) {
    leaves_ = v;
}

void intermediate_model::leaves(const std::unordered_set<dogen::yarn::name>&& v) {
    leaves_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::module>& intermediate_model::modules() const {
    return modules_;
}

std::unordered_map<std::string, dogen::yarn::module>& intermediate_model::modules() {
    return modules_;
}

void intermediate_model::modules(const std::unordered_map<std::string, dogen::yarn::module>& v) {
    modules_ = v;
}

void intermediate_model::modules(const std::unordered_map<std::string, dogen::yarn::module>&& v) {
    modules_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::concept>& intermediate_model::concepts() const {
    return concepts_;
}

std::unordered_map<std::string, dogen::yarn::concept>& intermediate_model::concepts() {
    return concepts_;
}

void intermediate_model::concepts(const std::unordered_map<std::string, dogen::yarn::concept>& v) {
    concepts_ = v;
}

void intermediate_model::concepts(const std::unordered_map<std::string, dogen::yarn::concept>&& v) {
    concepts_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::primitive>& intermediate_model::primitives() const {
    return primitives_;
}

std::unordered_map<std::string, dogen::yarn::primitive>& intermediate_model::primitives() {
    return primitives_;
}

void intermediate_model::primitives(const std::unordered_map<std::string, dogen::yarn::primitive>& v) {
    primitives_ = v;
}

void intermediate_model::primitives(const std::unordered_map<std::string, dogen::yarn::primitive>&& v) {
    primitives_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::enumeration>& intermediate_model::enumerations() const {
    return enumerations_;
}

std::unordered_map<std::string, dogen::yarn::enumeration>& intermediate_model::enumerations() {
    return enumerations_;
}

void intermediate_model::enumerations(const std::unordered_map<std::string, dogen::yarn::enumeration>& v) {
    enumerations_ = v;
}

void intermediate_model::enumerations(const std::unordered_map<std::string, dogen::yarn::enumeration>&& v) {
    enumerations_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::object>& intermediate_model::objects() const {
    return objects_;
}

std::unordered_map<std::string, dogen::yarn::object>& intermediate_model::objects() {
    return objects_;
}

void intermediate_model::objects(const std::unordered_map<std::string, dogen::yarn::object>& v) {
    objects_ = v;
}

void intermediate_model::objects(const std::unordered_map<std::string, dogen::yarn::object>&& v) {
    objects_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::exception>& intermediate_model::exceptions() const {
    return exceptions_;
}

std::unordered_map<std::string, dogen::yarn::exception>& intermediate_model::exceptions() {
    return exceptions_;
}

void intermediate_model::exceptions(const std::unordered_map<std::string, dogen::yarn::exception>& v) {
    exceptions_ = v;
}

void intermediate_model::exceptions(const std::unordered_map<std::string, dogen::yarn::exception>&& v) {
    exceptions_ = std::move(v);
}

const std::unordered_map<std::string, dogen::yarn::visitor>& intermediate_model::visitors() const {
    return visitors_;
}

std::unordered_map<std::string, dogen::yarn::visitor>& intermediate_model::visitors() {
    return visitors_;
}

void intermediate_model::visitors(const std::unordered_map<std::string, dogen::yarn::visitor>& v) {
    visitors_ = v;
}

void intermediate_model::visitors(const std::unordered_map<std::string, dogen::yarn::visitor>&& v) {
    visitors_ = std::move(v);
}

bool intermediate_model::is_target() const {
    return is_target_;
}

void intermediate_model::is_target(const bool v) {
    is_target_ = v;
}

bool intermediate_model::has_generatable_types() const {
    return has_generatable_types_;
}

void intermediate_model::has_generatable_types(const bool v) {
    has_generatable_types_ = v;
}

const dogen::yarn::indices& intermediate_model::indices() const {
    return indices_;
}

dogen::yarn::indices& intermediate_model::indices() {
    return indices_;
}

void intermediate_model::indices(const dogen::yarn::indices& v) {
    indices_ = v;
}

void intermediate_model::indices(const dogen::yarn::indices&& v) {
    indices_ = std::move(v);
}

} }
