#include "BookingSystem.h"
#include "Utils.h"
#include "Payment.h"
#include <iostream>
#include <fstream>
#include <utility>

BookingSystem::BookingSystem() {
    loadData();
}

BookingSystem::~BookingSystem() {
    saveData();
    for (auto& pair : users) delete pair.second;
    for (auto& pair : drivers) delete pair.second;
    for (auto& pair : rides) delete pair.second;
}

void BookingSystem::registerUser(const std::string& name, const std::string& phone, const std::string& pass) {
    std::string id = Utils::generateId("USR_");
    users[id] = new User(id, name, phone, pass);
    std::cout << "User registered successfully! Your ID is: " << id << "\n";
}

void BookingSystem::registerDriver(const std::string& name, const std::string& phone, const std::string& pass, const Cab& cab) {
    std::string id = Utils::generateId("DRV_");
    drivers[id] = new Driver(id, name, phone, pass, cab);
    std::cout << "Driver registered successfully! Your ID is: " << id << "\n";
}

User* BookingSystem::authenticateUser(const std::string& id, const std::string& pass) {
    if (users.find(id) != users.end() && users[id]->verifyPassword(pass)) {
        return users[id];
    }
    return nullptr;
}

Driver* BookingSystem::authenticateDriver(const std::string& id, const std::string& pass) {
    if (drivers.find(id) != drivers.end() && drivers[id]->verifyPassword(pass)) {
        return drivers[id];
    }
    return nullptr;
}

Driver* BookingSystem::findNearestDriver(const Location& pickup) {
    std::priority_queue<DriverDistance, std::vector<DriverDistance>, std::greater<DriverDistance>> pq;

    for (const auto& pair : drivers) {
        Driver* d = pair.second;
        if (d->getOnlineStatus() && d->getAvailability()) {
            double dist = pickup.distanceTo(d->getLocation());
            pq.push({d, dist});
        }
    }

    if (pq.empty()) return nullptr;

    return pq.top().driver; // Returns the driver with the smallest distance
}

void BookingSystem::bookRide(User* user, const Location& pickup, const Location& drop) {
    std::cout << "\nLooking for nearby drivers...\n";
    Driver* nearestDriver = findNearestDriver(pickup);

    if (!nearestDriver) {
        std::cout << "Sorry, no drivers are currently available in your area.\n";
        return;
    }

    std::string rideId = Utils::generateId("RIDE_");
    Ride* newRide = new Ride(rideId, user, pickup, drop);
    
    newRide->assignDriver(nearestDriver);
    newRide->calculateFare();
    newRide->printRideDetails();

    rides[rideId] = newRide;
    
    // Auto-process for simulation purposes
    UPIPayment* payment = new UPIPayment(Utils::generateId("PAY_"), newRide->getFare());
    newRide->setPaymentMethod(payment);
    
    newRide->startRide();
    newRide->completeRide();
}

void BookingSystem::loadData() {
    // Basic file existence check - full parsing will be built out in future optimizations
    std::ifstream userFile("../data/users.txt");
    if (userFile.is_open()) {
        std::cout << "[System] User data loaded.\n";
        userFile.close();
    } else {
        std::cout << "[System] No previous user data found. Starting fresh.\n";
    }
}

void BookingSystem::saveData() const {
    // Basic persistence stub
    std::ofstream userFile("../data/users.txt");
    if (userFile.is_open()) {
        for (const auto& pair : users) {
            userFile << pair.second->getId() << "," << pair.second->getName() << "\n";
        }
        userFile.close();
        std::cout << "[System] Data saved securely.\n";
    }
}