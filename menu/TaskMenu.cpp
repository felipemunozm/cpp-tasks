#include "TaskMenu.hpp"
#include <iostream>
TaskMenu::TaskMenu(){}

TaskMenu::~TaskMenu(){}

void TaskMenu::displayMenu() {
    int choice;
    do{
        std::cout << "What do you want to do with tasks?" << std::endl;
        std::cout << "(1) Add Task" << std::endl;
        std::cout << "(2) Search Task by Id" << std::endl;
        std::cout << "(3) Delete Task by Id" << std::endl;
        std::cout << "(0) Return" << std::endl;
        std::cout << "Enter an option..." << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "You selected Option 1" << std::endl;
                break;
            case 2:
                std::cout << "You selected Option 2" << std::endl;
                break;
            case 3:
                std::cout << "You selected Option 3" << std::endl;
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 4." << std::endl;
        }


    } while (choice != 0);
}