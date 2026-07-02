#include "Location.h"
#include <cmath>
#include <utility>

Location::Location(double x, double y, std::string name)
    : x(x), y(y), name(std::move(name)) {}

double Location::getX() const { return x; }
double Location::getY() const { return y; }
std::string Location::getName() const { return name; }

void Location::setLocation(double x, double y, const std::string& name) {
    this->x = x;
    this->y = y;
    if (!name.empty()) {
        this->name = name;
    }
}

double Location::distanceTo(const Location& other) const {
    return std::hypot(this->x - other.x, this->y - other.y);
}