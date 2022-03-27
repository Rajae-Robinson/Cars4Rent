#ifndef CAR_H
#define CAR_H
#include<iostream>
#include<string>
#include "Vehicle.h"

class Car: public Vehicle {
    private:
        string interiorType;

    public:
        Car() {
            this->interiorType = 'Nylon';
        }

        Car(string interiorType) {
            this->interiorType = interiorType;
        }

        void setInteriorType() {
            this->interiorType = interiorType;
        }

        string getInteriorType() const {
            return interiorType;
        }
};

#endif
