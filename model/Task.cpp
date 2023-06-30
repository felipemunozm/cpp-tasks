#include "Task.hpp"

Task::Task(){}
Task::Task(TaskData &taskData) {
    this->taskData = taskData;
}
Task::~Task(){}

void Task::setId(const int &id) {
    this->taskData.id = id;
}
int Task::getId() {
    return this->taskData.id;
}

void Task::setTitle(const std::string &title) {
    this->taskData.title = title;
}

std::string Task::getTitle() {
    return this->taskData.title;
}

void Task::setDescription(const std::string &description) {
    this->taskData.description = description;
}

std::string Task::getDescription() {
    return this->taskData.description;
}

void Task::setCreationDate(const std::tm &creationDate) {
    this->taskData.creationDate = creationDate;
}
std::tm Task::getCreationDate() {
    return this->taskData.creationDate;
}

void Task::setDueDate(const std::tm &dueDate) {
    this->taskData.dueDate = dueDate;
}
std::tm Task::getDueDate() {
    return this->taskData.dueDate;
}
void Task::setcompletionDate(const std::tm &completionDate) {
    this->taskData.completionDate = completionDate;
}
std::tm Task::getCompletionDate() {
    return this->taskData.completionDate;
}
