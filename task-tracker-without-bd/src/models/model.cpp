#include "model.hpp"

namespace convert {
    Task TaskFromJson(const userver::formats::json::Value& json) {
        Task t;
        t.task_name = json["title"].As<std::string>();
        t.description = json["description"].As<std::string>();
        t.status = json["status"].As<std::string>();
        return t;
    }

    userver::formats::json::Value TaskToJson(const Task& task) {
        userver::formats::json::ValueBuilder builder(userver::formats::json::Type::kObject);

        builder.EmplaceNocheck("id", task.id);
        builder.EmplaceNocheck("title", task.task_name);
        builder.EmplaceNocheck("description", task.description);
        builder.EmplaceNocheck("status", task.status);

        userver::formats::json::Value value = builder.ExtractValue();

        return value;
    }
} // namespace convert