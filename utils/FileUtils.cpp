#include "FileUtils.hpp"
#include <iostream>
#include <fstream>

template<typename T>
FileUtils<T>::FileUtils(/* args */){}

template<typename T>
FileUtils<T>::~FileUtils(){}

template<typename T>
bool FileUtils<T>::writeToFile(const std::string &fileName, const T &data) {
    std::ofstream outputFile(fileName,std::ios::binary | std::ios::app);
    if(outputFile.is_open()) {
        outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
        outputFile.close();
        std::cout << "Written to file: " << fileName << " and TaskData: " << reinterpret_cast<const char*>(&data) << std::endl;
    } else {
        std::cerr << "Failed to open the file " << fileName << std::endl;
        return false;
    }
    return true;
}
