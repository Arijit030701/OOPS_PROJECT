#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"

class Admin : public Person {
public:
    Admin(std::string id, std::string name, std::string phone, std::string password);
    
    void displayProfile() const override;
};

#endif