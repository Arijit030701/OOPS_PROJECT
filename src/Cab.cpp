#include "Cab.h"
#include <utility>

Cab::Cab(std::string type, std::string plate) 
    : cabType(std::move(type)), licensePlate(std::move(plate)) {
    
    // Encapsulated logic to set rates based on the category
    if (cabType == "SUV") {
        baseFare = 100.0;
        perKmRate = 20.0;
    } else if (cabType == "Sedan") {
        baseFare = 80.0;
        perKmRate = 15.0;
    } else {
        cabType = "Mini"; // Default fallback
        baseFare = 50.0;
        perKmRate = 10.0;
    }
}

std::string Cab::getCabType() const { return cabType; }
std::string Cab::getLicensePlate() const { return licensePlate; }
double Cab::getBaseFare() const { return baseFare; }
double Cab::getPerKmRate() const { return perKmRate; }