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
        std::ofstream outputFile(fileName, std::ios::binary | std::ios::app);
        if (outputFile.is_open())
        {
            outputFile.write(reinterpret_cast<const char *>(&data), sizeof(data));
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
        T retrivedData;
        std::ifstream inputFile(fileName, std::ios::binary);
        if (inputFile.is_open())
        {
            while (true)
            {
                
                if (!inputFile.read(reinterpret_cast<char *>(&retrivedData), sizeof(retrivedData)))
                {
                    break;
                }
                if (retrivedData.id == id)
                {
                    std::cout << "Encontrado registro con Id: " << retrivedData.id << std::endl;
                    inputFile.close();
                    T *returnPointer = &retrivedData;
                    return returnPointer;
                }
            }
        }
        else
        {
            std::cerr << "Failed to open the file " << fileName << " to read" << std::endl;
        }
        return nullptr;
    }
};

#endif