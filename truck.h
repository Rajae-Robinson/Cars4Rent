#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

using namespace std;

class Truck: public Vehicle {
    private:
        string truckInteriorType;
        float towingCapacity;

    public:
        Truck(string licensePlateNumber, string brand, string model, string year, string color, float engineSize, string fuelType, string transmissionType, float mileage, int seatingCapacity, float ratePerDay, string rentalStatus, string truckInteriorType, float towingCapacity) {
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
            setTruckInteriorType(truckInteriorType);
            setTowingCapacity(towingCapacity);
        }

        void setTruckInteriorType(string truckInteriorType) {
            this->truckInteriorType = truckInteriorType;
        }

        string getTruckInteriorType() const {
            return truckInteriorType;
        }

        void setTowingCapacity(float towingCapacity) {
            this->towingCapacity = towingCapacity;
        }

        float getTowingCapacity() const {
            return towingCapacity;
        }

        void storeVehicle() const {
            /*
                Add truck information to a file
            */
            try {
                ofstream outFile("trucks.mds", std::ios::out);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << getLicensePlateNum() << "\t" << getBrand() << "\t" << getModel() << "\t" << getYear() << "\t"
                        << getColor() << "\t" << getEngineSize() << "\t" << getFuelType() << "\t" << getTransmissionType() << "\t"
                        << getMileage() << "\t" << getSeatingCapacity()
                        << "\t" << getRatePerDay() << "\t" << getTruckInteriorType() << "\t" << getTowingCapacity() << "\t" << getRentalStatus() << endl;

                outFile.close();
            } catch(runtime_error &e) {
                cerr << e.what() << endl;
            }
        }
};
#endif
