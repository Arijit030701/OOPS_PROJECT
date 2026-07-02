#include "User.h"
#include <iostream>
#include <utility>

User::User(std::string id, std::string name, std::string phone, std::string password)
    : Person(std::move(id), std::move(name), std::move(phone), std::move(password)) {}

void User::displayProfile() const {
    std::cout << "--- User Profile ---\n"
              << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Phone: " << phone << "\n"
              << "--------------------\n";
}