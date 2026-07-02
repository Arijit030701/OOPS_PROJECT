#include "Utils.h"
#include <chrono>
#include <random>
#include <iomanip>
#include <sstream>
#include <cstdlib>

std::string Utils::generateId(const std::string& prefix) {
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_int_distribution<> dis(1000, 9999);
    return prefix + std::to_string(dis(gen));
}

std::string Utils::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Utils::clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}