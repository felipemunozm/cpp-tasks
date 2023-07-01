#include "Initial.hpp"
#include <iostream>
#include "TaskMenu.hpp"

Initial::Initial(){}
Initial::~Initial(){}

void Initial::displayMenu() {
    int choice;
    do{
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "(1) Task Menu" << std::endl;
        std::cout << "(0) Quit Program" << std::endl;
        std::cout << "Enter an option..." << std::endl;

        std::cin >> choice;
        TaskMenu taskMenu;
        switch (choice) {
            case 1:
                std::cout << "You selected Option 1" << std::endl;
                taskMenu.displayMenu();
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 4." << std::endl;
        }


    } while (choice != 0);
}