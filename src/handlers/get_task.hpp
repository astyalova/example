#pragma once

#include <userver/server/handlers/http_handler_json_base.hpp>
#include <userver/components/component_context.hpp>

#include "../models/model.hpp"

namespace get {

    class GetTasksHandler final : public userver::server::handlers::HttpHandlerBase {
    public:
        static constexpr std::string_view kName = "handler-get-task";

        GetTasksHandler(const userver::components::ComponentConfig& config,
                    const userver::components::ComponentContext& context)
        : HttpHandlerBase(config, context),
          storage_(&context.FindComponent<TaskStorage>()) {}

        std::string HandleRequestThrow(const userver::server::http::HttpRequest&, userver::server::request::RequestContext&) const override;

        private:
        TaskStorage* storage_;
    };
} // namespace get