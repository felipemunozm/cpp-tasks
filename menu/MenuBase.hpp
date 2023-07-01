#ifndef __MENU__
#define __MENU__ 1

class MenuBase
{
public:
    MenuBase();
    ~MenuBase();

    virtual void displayMenu() = 0;
};




#endif