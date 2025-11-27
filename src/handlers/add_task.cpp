#include "add_task.hpp"

namespace add {

    userver::formats::json::Value AddTaskHandler::HandleRequestJsonThrow(
        const userver::server::http::HttpRequest&,
        const userver::formats::json::Value& json,
        userver::server::request::RequestContext&) const {
        
        try {
        Task t = convert::TaskFromJson(json);

        int task_id = storage_->AddTask(std::move(t));
        const Task& added_task = storage_->GetTask(task_id);
        return userver::formats::json::MakeObject(
            "id", added_task.id,
            "title", added_task.task_name,
            "description", added_task.description,
            "status", added_task.status
        );
        } catch (userver::formats::json::MemberMissingException& e) {
            throw userver::server::handlers::ClientError(
                    userver::formats::json::MakeObject("error", "Bad Request"));
        }
    }
} // namespace add