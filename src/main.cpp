#include <iostream>
#include <vector>
#include "User.h"
#include "Driver.h"
#include "Admin.h"
#include "Cab.h"

int main() {
    std::cout << "--- Testing Phase 3 Concrete Entities ---\n\n";

    // 1. Create instances
    User user("USR_1001", "Alice Smith", "555-0101", "pass123");
    Admin admin("ADM_9001", "Bob Boss", "555-0999", "adminpass");
    
    Cab sedanCab("Sedan", "UP78-XYZ-1234");
    Driver driver("DRV_5001", "Charlie Wheel", "555-0555", "dpass123", sedanCab);

    // Set some driver state
    driver.setOnlineStatus(true);
    driver.setAvailability(true);
    driver.updateLocation(10.5, 20.2, "Downtown");
    driver.updateRating(4.8);

    // 2. Test Runtime Polymorphism using an array of base class pointers
    std::vector<Person*> people;
    people.push_back(&user);
    people.push_back(&admin);
    people.push_back(&driver);

    for (const auto* person : people) {
        // The correct displayProfile() is called automatically based on the object type
        person->displayProfile();
        std::cout << "\n";
    }

    return 0;
}