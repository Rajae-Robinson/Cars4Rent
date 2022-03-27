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
		float mileage;
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
			this->mileage = 1.0f;
			this->seatingCapacity = 0;
			this->rentalStatus = "no";
            this->ratePerDay = 0.0f;
		}
		
		// Setters
        void setLicensePlateNumber(string licensePlateNumber){
            this->licensePlateNumber= licensePlateNumber;
        }

        void setModel(string model){
            this->model = model;
        }

        void setYear(string year){
            this->year = year;
        }

        void setMileage(float mileage){
            this->mileage = mileage;
        }

        void setSeatingCapacity(int seatingCapacity){
            this->seatingCapacity = seatingCapacity;
        }

        void setEngineSize(float engineSize){
            this->engineSize = engineSize;
        }

        void setBrand(string brand){
            this->brand = brand;
        }

        void setColor(string color){
            this->color = color;
        }

        void setTransmissionType(string transmissionType){
            this->transmissionType = transmissionType;
        }

        void setFuelType(string fuelType){
            this->fuelType = fuelType;
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

        float getMileage() const{
            return mileage;
        }

        int getSeatingCapacity() const{
            return seatingCapacity;
        }

        float getEngineSize() const {
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
		virtual void storeVehicle() const = 0;
};
#endif
