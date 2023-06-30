#ifndef __FILE_UTILS_HPP__
#define __FILE_UTILS_HPP__ 1
#include <string>
#include "../model/Task.hpp"

template<typename T>
class FileUtils
{
private:
    /* data */
public:
    FileUtils();
    ~FileUtils();
    static bool writeToFile(const std::string &fileName, const T &data);
};




#endif