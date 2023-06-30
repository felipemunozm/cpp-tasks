#include "model/Task.hpp"
#include "utils/FileUtils.hpp"


int main()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *currentLocalTime = std::localtime(&currentTime);
    TaskData taskData;

    taskData.id = 1;
    taskData.title = "title";
    taskData.description = "description";
    taskData.creationDate = *currentLocalTime;
    taskData.dueDate = *currentLocalTime;
    taskData.completionDate = *currentLocalTime;
    Task::toString(taskData);

    FileUtils<TaskData>::writeToFile(TASK_FILENAME, taskData);
    return 0;
}