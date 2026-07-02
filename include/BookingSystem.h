#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include "User.h"
#include "Driver.h"
#include "Ride.h"

class BookingSystem {
private:

    std::unordered_map<std::string, User*> users;
    std::unordered_map<std::string, Driver*> drivers;
    std::unordered_map<std::string, Ride*> rides;

    // Helper structure for the priority queue to sort drivers by distance
    struct DriverDistance {
        Driver* driver;
        double distance;
        
        // Min-Heap comparator (smaller distance gets higher priority)
        bool operator>(const DriverDistance& other) const {
            return distance > other.distance;
        }
    };

public: 
    BookingSystem();
    ~BookingSystem(); 

    // Registration & Auth
    void registerUser(const std::string& name, const std::string& phone, const std::string& pass);
    void registerDriver(const std::string& name, const std::string& phone, const std::string& pass, const Cab& cab);
    
    User* authenticateUser(const std::string& id, const std::string& pass);
    Driver* authenticateDriver(const std::string& id, const std::string& pass);

    // Core Logic
    Driver* findNearestDriver(const Location& pickup);
    void bookRide(User* user, const Location& pickup, const Location& drop);

    // Persistence
    void loadData();
    void saveData() const;
};

#endif