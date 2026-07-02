#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Location.h"
#include "Cab.h"

class Driver : public Person {
private:
    bool isOnline;
    bool isAvailable;
    double rating;
    int totalRides;
    Location currentLocation;
    Cab driverCab; // Composition: A Driver HAS-A Cab

public:
    Driver(std::string id, std::string name, std::string phone, std::string password, Cab cab);

    void displayProfile() const override;

    // Status setters/getters
    void setOnlineStatus(bool status);
    bool getOnlineStatus() const;
    
    void setAvailability(bool status);
    bool getAvailability() const;

    void updateLocation(double x, double y, const std::string& locName);
    Location getLocation() const;

    Cab getCab() const;
    double getRating() const;
    void updateRating(double newRating);
};

#endif