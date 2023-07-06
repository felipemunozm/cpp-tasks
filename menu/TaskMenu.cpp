#include "TaskMenu.hpp"
#include <iostream>
#include <string>
#include "../utils/TimeUtils.hpp"
#include "../service/TaskService.hpp"
#include "../utils/FileUtils.hpp" 
#include <limits>
#include "../service/TaskService.hpp"

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
        std::cin.clear();
        std::cin >> choice;

        switch (choice) {
            case 1:
                this->addTaskMenu();
                break;
            case 2:
                this->searchTaskByIdMenu();
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


void TaskMenu::addTaskMenu() {
    std::string title, description, dueDate;
    std::cout << "Please enter the following information:" << std::endl;
    std::cout << "Title: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);
    std::cout << "Description: ";
    std::getline(std::cin, description);
    std::cout << "Due Date (format YYYY-MM-DD HH:MM:ss): ";
    std::getline(std::cin, dueDate);
    if(!TimeUtils_validateStringDateFormat(dueDate)) {
        std::cout << "Due Date does not fit pattern YYYY-MM-DD HH:MM:SS" << std::endl;
        return;
    }

    Task task;
    task.setTitle(title.c_str());
    task.setDescription(description.c_str());
    task.setDueDate(dueDate.c_str());
    task.setCreationDate(TimeUtils_getCurrentTimeString());
    TaskService taskService;
    Task *responseTask = taskService.saveTask(task);
    responseTask->toString();
    delete responseTask;
}

void TaskMenu::searchTaskByIdMenu() {
    int id;
    std::cout << "Enter the Task Id to search: " << std::endl;
    std::cin >> id;
    TaskService taskService;
    Task *task = taskService.getTask(id);
    if(task) {
        task->toString();
        delete task;
    }
    else
        std::cout << "Task Not Found" << std::endl;
}