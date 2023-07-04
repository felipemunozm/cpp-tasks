#ifndef __TIME_UTILS_HPP__
#define __TIME_UTILS_HPP__ 1

#include <string>

char *TimeUtils_getCurrentTimeString();

bool TimeUtils_validateStringDateFormat(const std::string &input);

#endif