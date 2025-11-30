#include "get_task_by_id.hpp"
#include <algorithm>

namespace getId {

    std::string GetTaskByIdHandler::HandleRequestThrow(
        const userver::server::http::HttpRequest& req, 
        userver::server::request::RequestContext&) const {
        try {
            std::unordered_map<int, Task> tasks = storage_->GetStorage();  
            std::string id_str = req.GetPathArg("id");
            int id = std::stoi(id_str);
            userver::formats::json::Value task = convert::TaskToJson(tasks[id]);
            return userver::formats::json::ToString(task);
        } catch(const std::exception& e){
            return R"({"error": "internal error"})";
        }
    }
} //namespace get

