#include "TaskService.hpp"
#include "../utils/FileUtils.hpp"

TaskService::TaskService() {}

TaskService::~TaskService() {}

Task* TaskService::saveTask(const Task &task)
{
    TaskData taskData = task.getTaskData();
    TaskData savedTaskData = FileUtils<TaskData>::writeToFile(TASK_FILENAME, taskData);
    FileUtils<TaskData>::createIndex<int>(TASK_FILENAME, TASK_INDEXNAME, &TaskData::id);
    Task *taskPtr = new Task;
    taskPtr->setTaskData(savedTaskData);
    return taskPtr;
}