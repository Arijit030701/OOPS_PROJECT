#include "Payment.h"
#include <iostream>
#include <utility>


Payment::Payment(std::string id, double amt) 
    : paymentID(std::move(id)), amount(amt), isCompleted(false) {}

bool Payment::getStatus() const { return isCompleted; }
double Payment::getAmount() const { return amount; }
std::string Payment::getId() const { return paymentID; }

// --- Derived Classes Implementation ---

CashPayment::CashPayment(std::string id, double amt) : Payment(std::move(id), amt) {}
void CashPayment::processPayment() {
    std::cout << "[Cash] Collecting Rs. " << amount << " from passenger...\n";
    isCompleted = true;
    std::cout << "Payment Successful (ID: " << paymentID << ")\n";
}

CardPayment::CardPayment(std::string id, double amt) : Payment(std::move(id), amt) {}
void CardPayment::processPayment() {
    std::cout << "[Card] Connecting to payment gateway for Rs. " << amount << "...\n";
    isCompleted = true;
    std::cout << "Payment Successful (ID: " << paymentID << ")\n";
}

UPIPayment::UPIPayment(std::string id, double amt) : Payment(std::move(id), amt) {}
void UPIPayment::processPayment() {
    std::cout << "[UPI] Waiting for UPI PIN entry for Rs. " << amount << "...\n";
    isCompleted = true;
    std::cout << "Payment Successful (ID: " << paymentID << ")\n";
}