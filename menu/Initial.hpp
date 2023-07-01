#ifndef __INITIAL__
#define __INITIAL__ 1
#include "MenuBase.hpp"

class Initial : public MenuBase
{
public:
    Initial();
    ~Initial();

    void displayMenu() override;
};




#endif