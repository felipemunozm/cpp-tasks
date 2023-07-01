#ifndef __FILE_UTILS_HPP__
#define __FILE_UTILS_HPP__ 1
#include <string>
#include <iostream>
#include <fstream>

template <typename T>
class FileUtils
{
private:
    /* data */
public:
    FileUtils();
    ~FileUtils();
    static bool writeToFile(const std::string &fileName, const T &data)
    {
        if(!fileExists(fileName))
            data.id = 1;
        else
            data.id = getNextIdFromFile(fileName);
        std::ofstream outputFile(fileName, std::ios::binary | std::ios::app);
        if (outputFile.is_open())
        {
            outputFile.write(reinterpret_cast<const char *>(&data), sizeof(T));
            outputFile.close();
            std::cout << "Written to file: " << fileName << std::endl;
        }
        else
        {
            std::cerr << "Failed to open the file " << fileName << std::endl;
            return false;
        }
        return true;
    }

    static T *searchRegistry(const std::string &fileName, const int &id)
    {
        
        std::ifstream inputFile(fileName, std::ios::binary);
        if (inputFile.is_open())
        { 
            T *foundData = nullptr;
            while (true)
            {
                T currentData;
                if (!inputFile.read(reinterpret_cast<char *>(&currentData), sizeof(T)))
                {
                    break;
                }
                if (currentData.id == id)
                {
                    std::cout << "Encontrado registro con Id: " << currentData.id << std::endl;
                    inputFile.close();
                    foundData = new T(currentData);
                    return foundData;
                }
            }
        }
        else
        {
            std::cerr << "Failed to open the file " << fileName << " to read" << std::endl;
        }
        return nullptr;
    }

    static int getNextIdFromFile(const std::string &fileName) {
        std::ifstream inputFile(fileName, std::ios::binary);
        if(inputFile.is_open()) {
            T lastData;
            inputFile.seekg(-static_cast<std::streamoff>(sizeof(T)),std::ios::end);
            inputFile.read(reinterpret_cast<char *>(&lastData), sizeof(T));
            inputFile.close();
            return ++lastData.id;
        }
        else
            std::cerr << "Failed to open file " << fileName << std::endl;
        return 0;
    }

    static bool fileExists(const std::string& fileName)
    {
        std::ifstream file(fileName);
        return file.good();
    }
};

#endif