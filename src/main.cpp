#include <iostream>
#include "Utils.h"
#include "User.h"
#include "Driver.h"
#include "Ride.h"
#include "Payment.h"

int main() {
    std::cout << "--- Testing Phase 4: Full Ride Transaction ---\n\n";

    // 1. Setup Entities
    User alice("USR_1", "Alice Smith", "12345", "pass");
    Cab suvCab("SUV", "IND-9999");
    Driver bob("DRV_1", "Bob Driver", "67890", "pass", suvCab);
    bob.setOnlineStatus(true);
    bob.setAvailability(true);

    Location pickup(0.0, 0.0, "Home");
    Location drop(10.0, 0.0, "Airport"); // Distance will be exactly 10km

    // 2. Create the Ride
    std::string rideId = Utils::generateId("RIDE_");
    Ride ride(rideId, &alice, pickup, drop);
    
    // 3. Process the Transaction
    ride.assignDriver(&bob);
    ride.calculateFare();
    ride.printRideDetails();
    
    // 4. Handle Payment (Runtime Polymorphism in action!)
    UPIPayment upi(Utils::generateId("PAY_"), ride.getFare());
    ride.setPaymentMethod(&upi);
    
    // 5. Execute Trip
    ride.startRide();
    ride.completeRide();

    return 0;
}