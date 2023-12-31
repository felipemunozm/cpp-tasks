#ifndef __TASK_MENU__ 
#define __TASK_MENU__ 1
#include "MenuBase.hpp"

class TaskMenu : MenuBase
{
private:
    void addTaskMenu();
    void searchTaskByIdMenu();
    void deleteTaskMenu();
public:
    TaskMenu();
    ~TaskMenu();
    void displayMenu() override;
};



#endif