#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

using namespace std;

class Truck: public Vehicle {
    private:
        float towingCapacity;

    public:
        Truck() {
            this->towingCapacity = 1.0f;
        }

        Truck(float towingCapacity) {
            this->towingCapacity = towingCapacity;
        }
};
#endif
