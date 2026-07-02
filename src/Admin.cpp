#include "Admin.h"
#include <iostream>
#include <utility>

Admin::Admin(std::string id, std::string name, std::string phone, std::string password)
    : Person(std::move(id), std::move(name), std::move(phone), std::move(password)) {}

void Admin::displayProfile() const {
    std::cout << "--- Admin Profile ---\n"
              << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Role: System Administrator\n"
              << "---------------------\n";
}