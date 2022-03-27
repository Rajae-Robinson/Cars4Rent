#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Vehicle.h"

using namespace std;

class User {
	private:
		string customerName;
		string homeAddress;
		string phoneNumber;
		string dateRented; // dd-mm-yyyy
		string expectedReturnDate;
		float depositPaid;
		Vehicle vehicle;
		
	public:
		User()
		:vehicle() {
			this->customerName = "Name";
			this->homeAddress = "Address";
			this->phoneNumber = "876-555-5555";
			this->dateRented = "01-01-2022";
			this->expectedReturnDate = "02-02-2022";
			this->depositPaid = 1.0f;
		}
		
		User(string customerName, string homeAddress, string phoneNumber, string dateRented, string expectedReturnDate, float depositPaid, Vehicle vehicle)
		:vehicle(vehicle) {
			this->customerName = customerName;
			this->homeAddress = homeAddress;
			this->phoneNumber = phoneNumber;
			this->dateRented = dateRented;
			this->expectedReturnDate = expectedReturnDate;
			this->depositPaid = depositPaid;
		}
		
		// Setters
		void setCustomerName(string customerName) {
			this->customerName = customerName;
		}
		
		void setHomeAddress(string homeAddress) {
			this->homeAddress = homeAddress;
		}
		
		void setPhoneNumber(string phoneNumber) {
			this->phoneNumber = phoneNumber;
		}
		
		void setDateRented(string dateRented) {
			this->dateRented = dateRented;
		}
		
		void setExpectedReturnDate(string expectedReturnDate) {
			this->expectedReturnDate = expectedReturnDate;
		}
		
		void setDepositPaid(float depositPaid) {
			this->depositPaid = depositPaid;
		}
		
		// Getters
		string getCustomerName() const {
			return customerName;
		}
		
		string getHomeAddress() const {
			return homeAddress;
		}
		
		string getPhoneNumber() const {
			return phoneNumber;
		}
		
		string getDateRented() const {
			return dateRented;
		}
		
		string getExpectedReturnDate() const {
			return expectedReturnDate;
		}
		
		float getDepositPaid() const {
			return depositPaid;
		}
		
		// Methods
		void storeRentalInfo() {
			/*
				Stores user rental information to a file
			*/	
		}
		
		void viewVehicles() {
			/*
				Shows user a list of vehicles to choose from to rent by reading from vehicles.md file. Then get user information
			*/
		}
		
		void searchVehicles(string searchCriteria) {
			
		}
		
		void showRentals(int searchId) {
			
		}
		
		void returnVehicle(string licensePlateNumber) {
			
		}
};
#endif
