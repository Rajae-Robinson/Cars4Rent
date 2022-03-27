#ifndef BIKE_H
#define BIKE_H
#include "Vehicle.h"

using namespace std;

class Bike: public Vehicle {
    private:
        int numOfHelmets;

    public:
        Bike(string licensePlateNumber, string brand, string model, string year, string color, float engineSize, string fuelType, string transmissionType, float mileage, int seatingCapacity, float ratePerDay, string rentalStatus, int numOfHelmets) {
            setLicensePlateNumber(licensePlateNumber);
            setBrand(brand);
            setModel(model);
            setYear(year);
            setColor(color);
            setEngineSize(engineSize);
            setFuelType(fuelType);
            setTransmissionType(transmissionType);
            setMileage(mileage);
            setSeatingCapacity(seatingCapacity);
            setRatePerDay(ratePerDay);
            setRentalStatus(rentalStatus);
            setNumOfHelmets(numOfHelmets);
        }

        void setNumOfHelmets(int numOfHelmets) {
            this->numOfHelmets = numOfHelmets;
        }

        int getNumOfHelmets() const {
            return numOfHelmets;
        }

        void storeVehicle() const {
            /*
                Add bike information to a file
            */
            try {
                ofstream outFile("bikes.mds", std::ios::out);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << getLicensePlateNum() << "\t" << getBrand() << "\t" << getModel() << "\t" << getYear() << "\t"
                        << getColor() << "\t" << getEngineSize() << "\t" << getFuelType() << "\t" << getTransmissionType() << "\t"
                        << getMileage() << "\t" << getSeatingCapacity()
                        << "\t" << getRatePerDay() << "\t" << getNumOfHelmets() << "\t" << getRentalStatus() << endl;

                outFile.close();
            } catch(runtime_error &e) {
                cerr << e.what() << endl;
            }
        }
};
#endif
