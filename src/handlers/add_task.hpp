#pragma once

#include <userver/server/handlers/http_handler_json_base.hpp>
#include <userver/components/component_context.hpp>

#include "../models/model.hpp"

namespace add {

class AddTaskHandler final : public userver::server::handlers::HttpHandlerJsonBase {
public:
    static constexpr std::string_view kName = "handler-add-task";
    AddTaskHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context) 
                    : HttpHandlerJsonBase(config, context),
                    storage_(&context.FindComponent<TaskStorage>()) {}

    userver::formats::json::Value HandleRequestJsonThrow(const userver::server::http::HttpRequest&, const userver::formats::json::Value& json, userver::server::request::RequestContext&) const override;

    private:
    TaskStorage* storage_;
};

}    // namespace add