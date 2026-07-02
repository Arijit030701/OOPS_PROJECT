#ifndef RIDE_H
#define RIDE_H

#include <string>
#include "User.h"
#include "Driver.h"
#include "Location.h"
#include "Payment.h"

class Ride {
private:
    std::string rideID;
    
    // Using pointers because a Ride only references existing people, it doesn't create them.
    User* passenger;
    Driver* assignedDriver;
    Payment* paymentMethod; 

    Location pickupLocation;
    Location dropLocation;
    
    double distance;
    double totalFare;
    std::string status; // "Requested", "Ongoing", "Completed", "Cancelled"

public:
    Ride(std::string id, User* p, Location pickup, Location drop);
    
    void assignDriver(Driver* d);
    void calculateFare();
    void setPaymentMethod(Payment* p);
    
    void startRide();
    void completeRide();
    
    std::string getRideID() const;
    std::string getStatus() const;
    double getFare() const;
    
    void printRideDetails() const;
};

#endif