#include "Task.hpp"
#include <cstring>
#include <iostream>

Task::Task() {}

Task::~Task() {}

void Task::setId(const int &id)
{
    this->taskData.id = id;
}
int Task::getId()
{
    return this->taskData.id;
}

void Task::setTitle(const char *title)
{
    std::strcpy(this->taskData.title, title);
}

char* Task::getTitle()
{
    return this->taskData.title;
}

void Task::setDescription(const char *description)
{
    std::strcpy(this->taskData.description,description);
}

char *Task::getDescription()
{
    return this->taskData.description;
}

void Task::setCreationDate(const char *creationDate)
{
    std::strcpy(this->taskData.creationDate, creationDate);
}
char * Task::getCreationDate()
{
    return this->taskData.creationDate;
}

void Task::setDueDate(const char *dueDate)
{
    std::strcpy(this->taskData.dueDate, dueDate);
}
char *Task::getDueDate()
{
    return this->taskData.dueDate;
}
void Task::setCompletionDate(const char *completionDate)
{
    std::strcpy(this->taskData.completionDate, completionDate);
}
char *Task::getCompletionDate()
{
    return this->taskData.completionDate;
}

void Task::toString() {
    std::cout << "TaskData: \n\tid: " << this->taskData.id << std::endl;
    std::cout << "\ttitle: " << this->taskData.title << std::endl;
    std::cout << "\tdescription: " << this->taskData.description << std::endl;
    std::cout << "\tdueDate: " << this->taskData.dueDate << std::endl;    
    std::cout << "\tcreationDate: " << this->taskData.creationDate << std::endl;    
}

void Task::toString(TaskData &data) {
        std::cout << "Starting printing..." << std::endl;
        std::cout << "TaskData: \n\tid: " << data.id << std::endl;
        std::cout << "\ttitle: " << data.title << std::endl;
        std::cout << "\tdescription: " << data.description << std::endl;
        std::cout << "\tcreationDate: " << data.creationDate << std::endl;
        std::cout << "\tdueDate: " << data.dueDate << std::endl;
}

void Task::setTaskData(TaskData &data) {
    this->taskData = data;
}

TaskData Task::getTaskData() const {
    return this->taskData;
}
