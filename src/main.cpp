#include <iostream>
#include "BookingSystem.h"

int main() {
    std::cout << "--- Testing Phase 5: Core Booking Engine ---\n\n";

    BookingSystem system;

    // 1. Seed some data
    system.registerUser("Alice Smith", "555-0101", "pass123");
    
    Cab mini("Mini", "UP78-A-1111");
    Cab suv("SUV", "UP78-B-2222");
    
    system.registerDriver("Bob (Mini)", "555-0202", "dpass1", mini);
    system.registerDriver("Charlie (SUV)", "555-0303", "dpass2", suv);

    // *Note: In a real run, you would look at the console output to get the generated IDs
    // But for this test, we will just grab them from the map directly in the next phase. 
    
    std::cout << "\n--- Simulating Live System ---\n";
    
    // Log in a driver and set them online at a specific location
    // We will bypass the strict login for this quick unit test to test the algorithm
    Driver* testDriver = new Driver("TEST_DRV", "Dave Distance", "555", "pass", suv);
    testDriver->setOnlineStatus(true);
    testDriver->setAvailability(true);
    testDriver->updateLocation(2.0, 2.0, "Campus Gate");
    
    User* testUser = new User("TEST_USR", "Eve", "555", "pass");
    
    Location pickup(0.0, 0.0, "Hostel");
    Location dropoff(15.0, 15.0, "Railway Station");

    // Book the ride (this will trigger the min-heap search and full transaction)
    system.bookRide(testUser, pickup, dropoff);

    delete testDriver;
    delete testUser;

    return 0;
}