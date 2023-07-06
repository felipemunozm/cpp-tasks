#ifndef __TASK_SERVICE_HPP__
#define __TASK_SERVICE_HPP__ 1

#include "../model/Task.hpp"

class TaskService
{
private:
public:
    TaskService();
    ~TaskService();
    static Task *getTask(const int &id);
    static Task *saveTask(const Task &task);
    static Task updateTask(const Task &task);
    static void deleteTask(const int &id);
};

#endif