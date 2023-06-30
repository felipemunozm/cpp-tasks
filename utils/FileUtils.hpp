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
            std::cout << "Written to file: " << fileName << " and TaskData: " << reinterpret_cast<const char *>(&data) << std::endl;
        }
        else
        {
            std::cerr << "Failed to open the file " << fileName << std::endl;
            return false;
        }
        return true;
    }

    static T *searchRegistry(const std::string &fileName, const T &data)
    {
        std::ifstream inputFile(fileName, std::ios::binary);
        if (inputFile.is_open())
        {
            while (true)
            {
                T retrivedData;
                if (!inputFile.read(reinterpret_cast<char *>(&retrivedData), sizeof(retrivedData)))
                {
                    break;
                }
                if (retrivedData.id == data.id)
                {
                    inputFile.close();
                    return &retrivedData;
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