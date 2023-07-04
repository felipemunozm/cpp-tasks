#ifndef __FILE_UTILS_HPP__
#define __FILE_UTILS_HPP__ 1
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

template <typename T>
class FileUtils
{
private:
    /* data */
public:
    FileUtils();
    ~FileUtils();
    static T writeToFile(const std::string &fileName, T &data)
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
            return T();
        }
        return data;
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

    template<typename Key>
    static void createIndex(const std::string& fileName, const std::string &indexFileName, Key T:: *keyField) {
            std::unordered_map<Key, std::streampos> index;
            std::ifstream fileToIndex(fileName, std::ios::binary);
            if(fileToIndex.is_open()) {
                while(fileToIndex.peek() != EOF) {
                    std::streampos pos = fileToIndex.tellg();
                    T data;
                    if(fileToIndex.read(reinterpret_cast<char*>(&data),sizeof(T))) {
                        Key key = data.*keyField;
                        index[key] = pos;
                    }
                }
                fileToIndex.close();
                writeIndexToFile<Key>(indexFileName, index);
            }
            else {
                std::cerr << "Failed to write to file " << fileName << std::endl;
            }
    }

    template<typename Key>
    static void writeIndexToFile(const std::string &indexFileName, std::unordered_map<Key, std::streampos> &index) {
        std::ofstream indexFile(indexFileName, std::ios::binary);
        if(indexFile.is_open()) {
            for(const auto &pair: index) {
                Key key = pair.first;
                std::streampos pos = pair.second;

                indexFile.write(reinterpret_cast<const char*>(&key), sizeof(Key));
                indexFile.write(reinterpret_cast<const char*>(&pos), sizeof(std::streampos));
            }
            indexFile.close();
            std::cout << "Index was written" << std::endl;
        }
        else {
            std::cerr << "Failed to write to file " << indexFileName << std::endl;
        }
    }

};

#endif