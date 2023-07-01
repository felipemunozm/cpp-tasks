#include "model/Task.hpp"
#include "utils/FileUtils.hpp"
#include "utils/TimeUtils.hpp"
#include "menu/Initial.hpp"

int main()
{
    Task task;
    task.setId(1);
    task.setTitle("title");
    task.setDescription("description");
    task.setCreationDate(TimeUtils_getCurrentTimeString());
    task.setDueDate(TimeUtils_getCurrentTimeString());
    task.setCompletionDate(TimeUtils_getCurrentTimeString());
    TaskData taskData = task.getTaskData();
    Task::toString(taskData);

    FileUtils<TaskData>::writeToFile(TASK_FILENAME, taskData);

    TaskData *taskDataRetrived = FileUtils<TaskData>::searchRegistry(TASK_FILENAME, 1);
    
    std::cout << "recibido el Puntero de retorno" << std::endl;
    Task::toString(*taskDataRetrived);
    delete taskDataRetrived;

    Initial initial;
    initial.displayMenu();

    return 0;
}