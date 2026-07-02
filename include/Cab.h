#ifndef CAB_H
#define CAB_H

#include <string>

class Cab {
private:
    std::string cabType; // Mini, Sedan, SUV
    std::string licensePlate;
    double baseFare;
    double perKmRate;

public:
    Cab(std::string type = "Mini", std::string plate = "UNKNOWN");
    
    std::string getCabType() const;
    std::string getLicensePlate() const;
    double getBaseFare() const;
    double getPerKmRate() const;
};

#endif