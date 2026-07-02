#ifndef USER_H
#define USER_H

#include "Person.h"

class User : public Person {
public:
    // Inherits properties from Person
    User(std::string id, std::string name, std::string phone, std::string password);
    
    // Overriding the pure virtual function (Polymorphism)
    void displayProfile() const override;
};

#endif