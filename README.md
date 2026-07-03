#  Cab Booking Management System

##  Project Description
A robust, highly decoupled C++17 backend engine and interactive Command Line Interface (CLI) for a ride-hailing service. This system handles real-time automated spatial driver matching, dynamic fare computation, secure role-based state management, and seamless polymorphic payment processing.

##  Key Features
* **Interactive CLI:** Orchestrates full ride lifecycles from booking to payment directly in the terminal.
* **Optimized Routing Infrastructure:** Achieves O(1) user authentication and O(N log N) proximity-based driver assignment utilizing Min-Heaps and Hashmaps.
* **Dynamic Payment Gateway:** Enforces the Open/Closed Principle via virtual dispatch to handle extensible payments (Cash, Card, UPI) with minimal source code changes.
* **Secure Encapsulation:** Applies strict runtime polymorphism and inheritance to securely isolate User, Driver, and Admin states.

##  Tech Stack
* **Language:** C++17
* **Build System:** CMake
* **Core Concepts:** Object-Oriented Programming (OOP), SOLID Principles, Advanced Data Structures.

##  Prerequisites
* A C++17 compatible compiler (e.g., `g++` or `clang++`)
* CMake (version 3.10 or higher)
* Git

##  Installation & Build Instructions

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/yourusername/cab-booking-system.git](https://github.com/yourusername/cab-booking-system.git)
   cd cab-booking-system
