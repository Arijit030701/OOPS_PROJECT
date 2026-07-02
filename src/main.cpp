#include <iostream>
#include <string>
#include <limits>
#include "BookingSystem.h"
#include "Utils.h"
#include "Admin.h"
// --- Helper for pausing the console ---
void pauseConsole() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// --- Dashboards ---

void userDashboard(BookingSystem& system, User* user) {
    int choice = 0;
    while (choice != 4) {
        Utils::clearScreen();
        std::cout << "=== User Dashboard ===\n";
        std::cout << "Welcome, " << user->getName() << "!\n\n";
        std::cout << "1. Book a Ride\n";
        std::cout << "2. View Profile\n";
        std::cout << "3. View Ride History (Coming Soon)\n";
        std::cout << "4. Logout\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        if (choice == 1) {
            double px, py, dx, dy;
            std::string pName, dName;
            
            std::cout << "\n--- Book a Ride ---\n";
            std::cout << "Enter Pickup Location Name: ";
            std::cin >> pName;
            std::cout << "Enter Pickup X & Y coordinates (e.g., 2.5 4.0): ";
            std::cin >> px >> py;
            
            std::cout << "Enter Dropoff Location Name: ";
            std::cin >> dName;
            std::cout << "Enter Dropoff X & Y coordinates: ";
            std::cin >> dx >> dy;

            Location pickup(px, py, pName);
            Location dropoff(dx, dy, dName);
            
            system.bookRide(user, pickup, dropoff);
            pauseConsole();
        } 
        else if (choice == 2) {
            std::cout << "\n";
            user->displayProfile();
            pauseConsole();
        }
    }
}

void driverDashboard(BookingSystem& system, Driver* driver) {
    int choice = 0;
    while (choice != 5) {
        Utils::clearScreen();
        std::cout << "=== Driver Dashboard ===\n";
        std::cout << "Welcome, " << driver->getName() << "!\n";
        std::cout << "Status: " << (driver->getOnlineStatus() ? "ONLINE" : "OFFLINE") << "\n\n";
        std::cout << "1. Toggle Online/Offline Status\n";
        std::cout << "2. Update Current Location\n";
        std::cout << "3. View Profile\n";
        std::cout << "4. View Earnings (Coming Soon)\n";
        std::cout << "5. Logout\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        if (choice == 1) {
            bool current = driver->getOnlineStatus();
            driver->setOnlineStatus(!current);
            driver->setAvailability(!current);
            std::cout << "\nYou are now " << (!current ? "ONLINE and waiting for rides." : "OFFLINE.") << "\n";
            pauseConsole();
        } 
        else if (choice == 2) {
            double x, y;
            std::string locName;
            std::cout << "\nEnter Current Location Name: ";
            std::cin >> locName;
            std::cout << "Enter X & Y coordinates: ";
            std::cin >> x >> y;
            driver->updateLocation(x, y, locName);
            std::cout << "Location updated successfully.\n";
            pauseConsole();
        }
        else if (choice == 3) {
            std::cout << "\n";
            driver->displayProfile();
            pauseConsole();
        }
    }
}

// --- Main Menu ---

int main() {
    BookingSystem system;
    int mainChoice = 0;

    // Seed an admin account automatically
    Admin admin("ADM_001", "System Admin", "000-0000", "admin123");

    while (mainChoice != 6) {
        Utils::clearScreen();
        std::cout << "========================================\n";
        std::cout << "       C++ CAB BOOKING SYSTEM           \n";
        std::cout << "========================================\n";
        std::cout << "1. Register as User\n";
        std::cout << "2. Register as Driver\n";
        std::cout << "3. Login as User\n";
        std::cout << "4. Login as Driver\n";
        std::cout << "5. Login as Admin (Maintenance)\n";
        std::cout << "6. Exit Application\n";
        std::cout << "========================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;

        if (mainChoice == 1) {
            std::string name, phone, pass;
            std::cout << "\n--- User Registration ---\n";
            std::cout << "Enter Name (No spaces): "; std::cin >> name;
            std::cout << "Enter Phone: "; std::cin >> phone;
            std::cout << "Enter Password: "; std::cin >> pass;
            system.registerUser(name, phone, pass);
            pauseConsole();
        }
        else if (mainChoice == 2) {
            std::string name, phone, pass, type, plate;
            std::cout << "\n--- Driver Registration ---\n";
            std::cout << "Enter Name (No spaces): "; std::cin >> name;
            std::cout << "Enter Phone: "; std::cin >> phone;
            std::cout << "Enter Password: "; std::cin >> pass;
            std::cout << "Enter Cab Type (Mini/Sedan/SUV): "; std::cin >> type;
            std::cout << "Enter License Plate: "; std::cin >> plate;
            
            Cab cab(type, plate);
            system.registerDriver(name, phone, pass, cab);
            pauseConsole();
        }
        else if (mainChoice == 3) {
            std::string id, pass;
            std::cout << "\n--- User Login ---\n";
            std::cout << "Enter User ID: "; std::cin >> id;
            std::cout << "Enter Password: "; std::cin >> pass;
            
            User* u = system.authenticateUser(id, pass);
            if (u) {
                userDashboard(system, u);
            } else {
                std::cout << "Invalid ID or Password!\n";
                pauseConsole();
            }
        }
        else if (mainChoice == 4) {
            std::string id, pass;
            std::cout << "\n--- Driver Login ---\n";
            std::cout << "Enter Driver ID: "; std::cin >> id;
            std::cout << "Enter Password: "; std::cin >> pass;
            
            Driver* d = system.authenticateDriver(id, pass);
            if (d) {
                driverDashboard(system, d);
            } else {
                std::cout << "Invalid ID or Password!\n";
                pauseConsole();
            }
        }
        else if (mainChoice == 5) {
            std::string id, pass;
            std::cout << "\n--- Admin Login ---\n";
            std::cout << "Enter Admin ID: "; std::cin >> id;
            std::cout << "Enter Password: "; std::cin >> pass;
            
            if (admin.getId() == id && admin.verifyPassword(pass)) {
                std::cout << "\nLogin Successful.\n";
                admin.displayProfile();
                std::cout << "[System Logs & Financials Menu Under Construction]\n";
                pauseConsole();
            } else {
                std::cout << "Unauthorized access.\n";
                pauseConsole();
            }
        }
    }

    std::cout << "\nSaving data and shutting down gracefully... Goodbye!\n";
    return 0;
}