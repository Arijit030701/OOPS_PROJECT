#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:

    static std::string generateId(const std::string& prefix);
    static std::string getCurrentTimestamp();
    static void clearScreen();
};

#endif