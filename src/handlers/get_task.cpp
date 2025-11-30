#include "get_task.hpp"

namespace get {


        std::string GetTasksHandler::HandleRequestThrow(
            const userver::server::http::HttpRequest&, 
            userver::server::request::RequestContext&) const {
        try {
            std::unordered_map<int, Task> tasks = storage_->GetStorage();
            userver::formats::json::ValueBuilder arr(userver::formats::json::Type::kArray);
            for(const auto& [key, value] : tasks) {
                arr.PushBack(convert::TaskToJson(value));
            }
            return userver::formats::json::ToString(arr.ExtractValue());
        } catch(const std::exception& e){
            return R"({"error": "internal error"})";
        }
    }
} //namespace get