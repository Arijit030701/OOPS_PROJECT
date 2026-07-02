#include "Driver.h"
#include <iostream>
#include <utility>

Driver::Driver(std::string id, std::string name, std::string phone, std::string password, Cab cab)
    : Person(std::move(id), std::move(name), std::move(phone), std::move(password)),
      isOnline(false), isAvailable(false), rating(5.0), totalRides(0), 
      currentLocation(0.0, 0.0, "Unknown"), driverCab(std::move(cab)) {}

void Driver::displayProfile() const {
    std::cout << "--- Driver Profile ---\n"
              << "ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Phone: " << phone << "\n"
              << "Rating: " << rating << " / 5.0\n"
              << "Cab: " << driverCab.getCabType() << " (" << driverCab.getLicensePlate() << ")\n"
              << "Status: " << (isOnline ? (isAvailable ? "Online & Available" : "On a Ride") : "Offline") << "\n"
              << "----------------------\n";
}

void Driver::setOnlineStatus(bool status) { 
    isOnline = status; 
    if (!isOnline) isAvailable = false; // Cannot be available if offline
}
bool Driver::getOnlineStatus() const { return isOnline; }

void Driver::setAvailability(bool status) { isAvailable = status; }
bool Driver::getAvailability() const { return isAvailable; }

void Driver::updateLocation(double x, double y, const std::string& locName) {
    currentLocation.setLocation(x, y, locName);
}
Location Driver::getLocation() const { return currentLocation; }

Cab Driver::getCab() const { return driverCab; }
double Driver::getRating() const { return rating; }

void Driver::updateRating(double newRating) {
    double totalScore = rating * totalRides;
    totalScore += newRating;
    totalRides++;
    rating = totalScore / totalRides;
}