#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
	private:
		string customerName;
		string homeAddress;
		string phoneNumber;
		string dateRented; // dd-mm-yyyy
		string expectedReturnDate;
		float depositPaid;
		
	public:
		User() {
			this->customerName = "Name";
			this->homeAddress = "Address";
			this->phoneNumber = "876-555-5555";
			this->dateRented = "01-01-2022";
			this->expectedReturnDate = "02-02-2022";
			this->depositPaid = 1.0f;
		}
		
		User(string customerName, string homeAddress, string phoneNumber, string dateRented, string expectedReturnDate, float depositPaid) {
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
            cout << "\t----- CARS ------" << endl;
            cout << "PLATE\tBRAND\tMODEL\tYEAR\tCOLOR\tENGINE\tFUEL\tTRANSMISSION\tMILEAGE\tSEATING CAPACITY\tRATE\tINTERIOR\tRENTED" << endl;
            // Read from cars
            try {
                string carsOutput;

                ifstream inFile("cars.mds", std::ios::in);

                if(inFile.fail()) {
                    throw std::runtime_error("Cannot read from file");
                }

                while (getline (inFile, carsOutput)) {
                    // Output the text from the file
                    cout << carsOutput << endl;
                }

                inFile.close();
            } catch(std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }

            cout << "\n\t----- TRUCKS ------" << endl;
            // Read from trucks
            try {
                string trucksOutput;

                ifstream inFile("trucks.mds", std::ios::in);

                if(inFile.fail()) {
                    throw std::runtime_error("Cannot read from file");
                }

                while (getline (inFile, trucksOutput)) {
                    // Output the text from the file
                    cout << trucksOutput << endl;
                }

                inFile.close();
            } catch(std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }


            cout << "\n\t----- BIKES ------" << endl;
            // Read from bikes
            try {
                string bikesOutput;

                ifstream inFile("bikes.mds", std::ios::in);

                if(inFile.fail()) {
                    throw std::runtime_error("Cannot read from file");
                }

                while (getline (inFile, bikesOutput)) {
                    // Output the text from the file
                    cout << bikesOutput << endl;
                }

                inFile.close();
            } catch(std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }

            string plateNum;
            string tempName;
            cout << "Please select the license plate number of the vehicle you want to rent: " << endl;
            cin >> plateNum;

            cout << "Please enter your name: " << endl;
            setCustomerName(tempName);

		}
		
		void searchVehicles(string searchCriteria) {
			
		}
		
		void showRentals(int searchId) {
			
		}
		
		void returnVehicle(string licensePlateNumber) {
			
		}
};
#endif
