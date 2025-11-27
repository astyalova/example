#include <string>
#include <unordered_map>
#include <userver/engine/mutex.hpp>
#include <userver/components/component_base.hpp>

struct Task {
    int id;
    std::string task_name;
    std::string description;
    std::string status;
};

class TaskStorage : public userver::components::ComponentBase {
public:
    static constexpr std::string_view kName = "task-storage";

    TaskStorage(const userver::components::ComponentConfig& config,
                const userver::components::ComponentContext& context)
        : ComponentBase(config, context) {}
        
    const std::unordered_map<int, Task>& GetStorage();
    int AddTask(const Task& task);
    const Task& GetTask(int idx);
    void DeleteTask(int id);

private:
    userver::engine::Mutex mutex_;
    std::unordered_map<int, Task> storage_;
    int task_id = 1;
};
