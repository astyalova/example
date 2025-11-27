#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "../components/task_storage_component.hpp"

namespace convert {
    Task TaskFromJson(const userver::formats::json::Value& json);
    userver::formats::json::Value TaskToJson(const Task& task);

} // namespace convert

