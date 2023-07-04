#include "TaskMenu.hpp"
#include <iostream>
#include <string>
#include "../utils/TimeUtils.hpp"
#include "../service/TaskService.hpp"
#include "../utils/FileUtils.hpp" 

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
                std::cout << "You selected Option 1:\n";
                this->addTaskMenu();
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


void TaskMenu::addTaskMenu() {
    std::string title, description, dueDate;
    std::cout << "Please enter the following information: Tile:";
    // std::cout << "Title: ";
    std::cin >> title;
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
    TaskData taskData = task.getTaskData();
    TaskData data = FileUtils<TaskData>::writeToFile(TASK_FILENAME, taskData);
    Task::toString(data);
    FileUtils<TaskData>::createIndex<int>(TASK_FILENAME, TASK_INDEXNAME, &TaskData::id);
}