#ifndef BIKE_H
#define BIKE_H
#include "Vehicle.h"

using namespace std;

class Bike: public Vehicle {
    private:
        int numOfHelmets;

    public:
        Bike() {
            this->numOfHelmets;
        }

        Bike(int numOfHelmets) {
            this->numOfHelmets = numOfHelmets;
        }

        void setNumOfHelmets(int numOfHelmets) {
            this->numOfHelmets = numOfHelmets;
        }

        int getNumOfHelmets() const {
            return numOfHelmets;
        }
};
#endif
