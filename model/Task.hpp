#ifndef _TASK_HPP_
#define _TASK_HPP_ 1
#include <string>
#include <ctime>
#include <iostream>

// Nombre de archivo a utilizar para almacenar estos registros
#define TASK_FILENAME "Task.data"
#define TASK_INDEXNAME "Task.idx"

struct TaskData
{
    int id;
    char title[50];
    char description[50];
    char creationDate[50];
    char dueDate[50];
    char completionDate[50];
};

class Task
{
private:
    TaskData taskData;

public:
    Task();
    ~Task();

    void setId(const int &id);
    int getId();

    char *getTitle();
    void setTitle(const char *title);

    char *getDescription();
    void setDescription(const char *description);

    void setCreationDate(const char *creationDate);
    char *getCreationDate();

    void setDueDate(const char *dueDate);
    char *getDueDate();

    void setCompletionDate(const char *completionDate);
    char *getCompletionDate();

    void toString();

    static void toString(TaskData data);

    TaskData getTaskData();
};

#endif