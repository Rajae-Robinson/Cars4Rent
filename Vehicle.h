#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vehicle {
	protected:
		string licensePlateNumber;
		string brand;
		string model;
		string year;
		string color;
		float engineSize;
		string fuelType;
		string transmissionType;
		string mileage;
		int seatingCapacity;
		string rentalStatus;
		float ratePerDay;
		
	public:
		Vehicle() {
			this->licensePlateNumber = '0';
			this->brand = "brand";
			this->model = "model";
			this->year = "year";
			this->color = "color";
			this->engineSize = 1.0f;
			this->fuelType = "fuel type";
			this->transmissionType = "transmission type";
			this->mileage = "mileage";
			this->seatingCapacity = 0;
			this->rentalStatus = "status";
		}
		
		Vehicle(string licensePlateNumber, string brand, string model, string year, string color, float engineSize, string fuelType, string transmissionType, string mileage, int seatingCapacity, string rentalStatus) {
			this->licensePlateNumber = licensePlateNumber;
			this->brand = brand;
			this->model = model;
			this->year = year;
			this->color = color;
			this->engineSize = engineSize;
			this->fuelType = fuelType;
			this->transmissionType = transmissionType;
			this->mileage = mileage;
			this->seatingCapacity = seatingCapacity;
			this->rentalStatus = rentalStatus;
		}
		
		// Setters
        void setLicensePlateNumber(string licensePlateNumber){
            this->licensePlateNumber= licensePlateNumber;
        }

        void setModel(string model){
            this->model= model;
        }

        void setYear(string year){
            this->year= year;
        }

        void setMileage(string mileage){
            this->mileage= mileage;
        }

        void setSeatingCapacity(int seatingCapacity){
            this->seatingCapacity = seatingCapacity;
        }

        void setEngineSize(float engineSize){
            this->engineSize= engineSize;
        }

        void setBrand(string brand){
            this->brand= brand;
        }

        void setColor(string color){
            this->color= color;
        }

        void setTransmissionType(string transmissionType){
            this->transmissionType= transmissionType;
        }

        void setFuelType(string fueltype){
            this->fuelType= fuelType;
        }

        void setRatePerDay(float ratePerDay){
            this->ratePerDay = ratePerDay;
        }

        void setRentalStatus(string rentalStatus) {
            this->rentalStatus = rentalStatus;
        }
		
		
		// Getters
        string getLicensePlateNum() const{
            return licensePlateNumber;
        }

        string getModel() const{
            return model;
        }

        string getYear() const{
            return year;
        }

        string getMileage() const{
            return mileage;
        }

        int getSeatingCapacity() const{
            return seatingCapacity;
        }

        float getEngineSize(){
            return engineSize;
        }

        string getBrand() const{
            return brand;
        }

        string getColor() const{
            return color;
        }

        string getTransmissionType() const{
            return transmissionType;
        }

        string getFuelType() const{
            return fuelType;
        }

        float getRatePerDay()const{
            return ratePerDay;
        }

        string getRentalStatus() const {
            return rentalStatus;
        }
		
		
		// Methods
		void storeVehicle() {
			/*
				Add vehicle information to a file
			*/
            try {
                ofstream outFile("vehicles.mds", std::ios::app);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << getLicensePlateNum() << "\t" << getBrand() << "\t" << getModel() << "\t" << getYear() << "\t"
                << getColor() << "\t" << getEngineSize() << "\t" << getFuelType() << getTransmissionType() << "\t" << getSeatingCapacity()
                << "\t" << getRatePerDay() << "\t" << getRentalStatus() << endl;

                outFile.close();

                cout << "Record stored successfully" << endl;
            } catch(runtime_error &e) {
                cerr << e.what() << endl;
            }
		}
};
#endif
