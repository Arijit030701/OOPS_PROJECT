#include "Ride.h"
#include <iostream>
#include <utility>

Ride::Ride(std::string id, User* p, Location pickup, Location drop)
    : rideID(std::move(id)), passenger(p), assignedDriver(nullptr), 
      paymentMethod(nullptr), pickupLocation(std::move(pickup)), 
      dropLocation(std::move(drop)), totalFare(0.0), status("Requested") {
    
    // Calculate distance immediately upon ride creation
    distance = pickupLocation.distanceTo(dropLocation);
}

void Ride::assignDriver(Driver* d) {
    assignedDriver = d;
    assignedDriver->setAvailability(false); // Driver is now busy
    status = "Driver Assigned";
}

void Ride::calculateFare() {
    if (!assignedDriver) {
        std::cout << "Cannot calculate fare without assigning a driver/cab first.\n";
        return;
    }
    
    // Formula: Base Fare + (Distance * PerKmRate) + Fixed GST
    double base = assignedDriver->getCab().getBaseFare();
    double perKm = assignedDriver->getCab().getPerKmRate();
    double gst = 1.18; // 18% GST
    
    totalFare = (base + (distance * perKm)) * gst;
}

void Ride::setPaymentMethod(Payment* p) {
    paymentMethod = p;
}

void Ride::startRide() {
    if (assignedDriver == nullptr) {
        std::cout << "Cannot start ride: No driver assigned.\n";
        return;
    }
    status = "Ongoing";
    std::cout << "Ride " << rideID << " has started. Enjoy your trip!\n";
}

void Ride::completeRide() {
    if (status != "Ongoing") {
        std::cout << "Cannot complete a ride that hasn't started.\n";
        return;
    }
    
    std::cout << "\n--- Completing Ride " << rideID << " ---\n";
    status = "Completed";
    assignedDriver->setAvailability(true); // Driver is free again
    assignedDriver->updateLocation(dropLocation.getX(), dropLocation.getY(), dropLocation.getName());
    
    if (paymentMethod) {
        paymentMethod->processPayment(); // Polymorphic call!
    } else {
        std::cout << "Warning: No payment method attached to this ride.\n";
    }
}

std::string Ride::getRideID() const { return rideID; }
std::string Ride::getStatus() const { return status; }
double Ride::getFare() const { return totalFare; }

void Ride::printRideDetails() const {
    std::cout << "\n--- Ride Ticket ---\n"
              << "Ride ID: " << rideID << "\n"
              << "Passenger: " << passenger->getName() << "\n"
              << "Pickup: " << pickupLocation.getName() << "\n"
              << "Drop: " << dropLocation.getName() << "\n"
              << "Distance: " << distance << " km\n"
              << "Status: " << status << "\n";
              
    if (assignedDriver) {
        std::cout << "Driver: " << assignedDriver->getName() 
                  << " (" << assignedDriver->getCab().getCabType() << ")\n"
                  << "Total Fare: Rs. " << totalFare << "\n";
    }
    std::cout << "-------------------\n";
}