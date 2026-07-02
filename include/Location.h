#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
private:
    double x;
    double y;
    std::string name;

public:
    Location(double x = 0.0, double y = 0.0, std::string name = "Unknown");

    double getX() const;
    double getY() const;
    std::string getName() const;

    void setLocation(double x, double y, const std::string& name = "");

    double distanceTo(const Location& other) const;
};

#endif