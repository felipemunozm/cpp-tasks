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

Task* TaskService::getTask(const int &id) {
    TaskData *taskDataPtr = FileUtils<TaskData>::searchRegistry(TASK_FILENAME, id);
    if(taskDataPtr) {
        Task *task;
        task = new Task;
        task->setTaskData(*taskDataPtr);
        return task;
    }
    return nullptr;
}