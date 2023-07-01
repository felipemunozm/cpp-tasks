#ifndef __TASK_MENU__ 
#define __TASK_MENU__ 1
#include "MenuBase.hpp"

class TaskMenu : MenuBase
{
public:
    TaskMenu(/* args */);
    ~TaskMenu();
    void displayMenu() override;
};



#endif