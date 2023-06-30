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
    std::string title;
    std::string description;
    std::tm creationDate;
    std::tm dueDate;
    std::tm completionDate;
};

class Task
{
private:
    TaskData taskData;

public:
    Task();
    Task(TaskData &data);
    ~Task();

    void setId(const int &id);
    int getId();

    std::string getTitle();
    void setTitle(const std::string &title);

    std::string getDescription();
    void setDescription(const std::string &description);

    void setCreationDate(const std::tm &creationDate);
    std::tm getCreationDate();

    void setDueDate(const std::tm &dueDate);
    std::tm getDueDate();

    void setcompletionDate(const std::tm &completionDate);
    std::tm getCompletionDate();

    void toString();

    static void toString(TaskData data);
};

#endif