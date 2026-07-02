#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Payment {
protected:
    std::string paymentID;
    double amount;
    bool isCompleted;

public:
    Payment(std::string id, double amt);
    virtual ~Payment() = default;

    virtual void processPayment() = 0; 

    bool getStatus() const;
    double getAmount() const;
    std::string getId() const;
};


class CashPayment : public Payment {
public:
    CashPayment(std::string id, double amt);
    void processPayment() override;
};

class CardPayment : public Payment {
public:
    CardPayment(std::string id, double amt);
    void processPayment() override;
};

class UPIPayment : public Payment {
public:
    UPIPayment(std::string id, double amt);
    void processPayment() override;
};

#endif