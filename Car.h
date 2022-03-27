#ifndef CAR_H
#define CAR_H
#include<iostream>
#include<string>
#include "Vehicle.h"

class Car: public Vehicle {
    private:
        string carInteriorType;

    public:
        Car(string licensePlateNumber, string brand, string model, string year, string color, float engineSize, string fuelType, string transmissionType, float mileage, int seatingCapacity, float ratePerDay, string rentalStatus, string carInteriorType) {
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
            setCarInteriorType(carInteriorType);
        }

        void setCarInteriorType(string carInteriorType) {
            this->carInteriorType = carInteriorType;
        }

        string getCarInteriorType() const {
            return carInteriorType;
        }

        void storeVehicle() const {
            /*
				Add car information to a file
			*/
            try {
                ofstream outFile("cars.mds", std::ios::out);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << getLicensePlateNum() << "\t" << getBrand() << "\t" << getModel() << "\t" << getYear() << "\t"
                        << getColor() << "\t" << getEngineSize() << "\t" << getFuelType() << "\t" << getTransmissionType() << "\t"
                        << getMileage() << "\t" << getSeatingCapacity()
                        << "\t" << getRatePerDay() << "\t" << getCarInteriorType() << "\t" << getRentalStatus() << endl;

                outFile.close();
            } catch(runtime_error &e) {
                cerr << e.what() << endl;
            }
        }
};

#endif
