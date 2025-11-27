#include "task_storage_component.hpp"

const std::unordered_map<int, Task>& TaskStorage::GetStorage() {
    std::lock_guard<userver::engine::Mutex> lock(mutex_);
    return storage_;
}

int TaskStorage::AddTask(const Task& task) {
    const std::lock_guard<userver::engine::Mutex> lock(mutex_);
    storage_[task_id] = task;
    storage_[task_id].id = task_id;
    return task_id++;
}

const Task& TaskStorage::GetTask(int idx) {
    std::lock_guard<userver::engine::Mutex> lock(mutex_);
    return storage_[idx];
}

void TaskStorage::DeleteTask(int id) {
    const std::lock_guard<userver::engine::Mutex> lock(mutex_);
    storage_.erase(id);
}
