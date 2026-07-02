#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string id;
    std::string name;
    std::string phone;
    std::string password;

public:
    Person(std::string id, std::string name, std::string phone, std::string password);
    
    virtual ~Person() = default; 

    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;

    bool verifyPassword(const std::string& pass) const;

    virtual void displayProfile() const = 0;
};

#endif