#include "TimeUtils.hpp"
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>
#include <iomanip>
#include <regex>

char* TimeUtils_getCurrentTimeString() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* localTime = std::localtime(&currentTime_t);
    std::stringstream stringStream;
    stringStream << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    std::string timeString = stringStream.str();

    char* result = new char[timeString.length() + 1];
    std::strcpy(result, timeString.c_str());

    return result;
}

bool TimeUtils_validateStringDateFormat(const std::string &userInput) {
    std::regex pattern(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})");
    return std::regex_match(userInput, pattern);
}