#include "Person.h"
#include <utility>

Person::Person(std::string id, std::string name, std::string phone, std::string password)
    : id(std::move(id)), name(std::move(name)), phone(std::move(phone)), password(std::move(password)) {}

std::string Person::getId() const { return id; }
std::string Person::getName() const { return name; }
std::string Person::getPhone() const { return phone; }

bool Person::verifyPassword(const std::string& pass) const {
    return password == pass;
}