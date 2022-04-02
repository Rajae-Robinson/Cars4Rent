#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"

using namespace std;

class User {
	private:
		string customerName;
		string homeAddress;
		string phoneNumber;
		Date dateRented;
		Date expectedReturnDate;
        Date actualReturnDate;
		float depositPaid;
		
	public:
		User() {
			this->customerName = "Name";
			this->homeAddress = "Address";
			this->phoneNumber = "876-555-5555";
			this->depositPaid = 1.0f;
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
		
		void setDateRented(Date dateRented) {
			this->dateRented = dateRented;
		}
		
		void setExpectedReturnDate(Date expectedReturnDate) {
			this->expectedReturnDate = expectedReturnDate;
		}

        void setActualReturnDate(Date actualReturnDate) {
            this->actualReturnDate = actualReturnDate;
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
		
		float getDepositPaid() const {
			return depositPaid;
		}
		
		// Methods
		void storeRentalInfo(string plateNum) {
			/*
				Stores user rental information to a file
			*/
            try {
                ofstream outFile("rentals.mds", std::ios::app);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << plateNum << "\t" << getCustomerName() << "\t" << getHomeAddress() << "\t" << getPhoneNumber() << "\t" << dateRented.dateString() << "\t"
                        << expectedReturnDate.dateString() << "\t" << getDepositPaid() << endl;

                cout << "Vehicle successfully rented." << endl;
                outFile.close();
            } catch(runtime_error &e) {
                cerr << e.what() << endl;
            }
		}

        void getRentalInfo() {
            /*
             * Get user input for their rental information
             *
             */
            string plateNum, tempName, tempAddress, tempPhoneNumber;
            int day, month, year;
            float deposit;
            cout << "Please select the license plate number of the vehicle you want to rent: " << endl;
            cin >> plateNum;
            cin.ignore();

            cout << "Please enter your name: " << endl;
            getline(cin, tempName);
            setCustomerName(tempName);

            cout << "Please enter your home address: " << endl;
            getline(cin, tempAddress);
            setHomeAddress(tempAddress);

            cout << "Please enter your phone number: " << endl;
            cin >> tempPhoneNumber;
            setPhoneNumber(tempPhoneNumber);

            cout << "Please enter today's day: e.g. Enter 18 if today is March 18th" << endl;
            cin >> day;
            cout << "Please enter current month as a numeral: (January is 01 and so on)" << endl;
            cin >> month;
            cout << "Please enter current year:" << endl;
            cin >> year;
            Date today(day, month, year);
            setDateRented(today);

            cout << "Please enter the day you will return the vehicle: e.g. Enter 18 if date is March 18th" << endl;
            cin >> day;
            cout << "Please enter month you will return the vehicle as a numeral: (January is 01 and so on)" << endl;
            cin >> month;
            cout << "Please enter year you will return the vehicle" << endl;
            cin >> year;
            Date tempExpectedReturnDate(day, month, year);
            setExpectedReturnDate(tempExpectedReturnDate);

            cout << "Enter your deposit amount:" << endl;
            cin >> deposit;
            setDepositPaid(deposit);

            storeRentalInfo(plateNum);
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

            getRentalInfo();
		}
		
		void searchVehicles() {
			/* Allow the user to search for a vehicle based on anyone of the following criteria:
                    1. license plate number
                    2. brand
                    3. model
                    4. year
                    5. interior
            */
            string searchCriteria;
            cout << "Enter search criteria:" << endl;
            cin >> searchCriteria;

		}
		
		void showRentals() {
    		/*
    		 *
    		 * Show all the vehicles the user has rented
    		 *
            */
            string searchId;
            cout << "Enter your id:" << endl;
            cin >> searchId;

		}

        string* retrieveRentalInfo(string plateNumSearch) {
            /* Search by license plate number to get expected return date */
            string* result = new string[2];
            try {
                ifstream inFile("rentals.mds", ios::in);

                if(inFile.fail()) {
                    throw runtime_error("Cannot read from file");
                }

                bool found = false;

                string plateNum, tempName, tempAddress, tempPhone, tempRentedDate, tempExpectedReturnDate, tempDeposit;
                int day, month, year;
                float deposit;

                while(!found && std::getline(inFile, plateNum, '\t')) {
                    getline(inFile, tempName, '\t');
                    getline(inFile, tempAddress, '\t');
                    getline(inFile, tempPhone, '\t');
                    getline(inFile, tempRentedDate, '\t');
                    getline(inFile, tempExpectedReturnDate, '\t');
                    getline(inFile, tempDeposit);

                    if(plateNum == plateNumSearch) {
                        found = true;
                    }
                }
                inFile.close();
                if(found) {
                    result[0] = tempExpectedReturnDate;
                    result[1] = tempDeposit;
                    return result;
                } else {
                    result[0] = "";
                    result[1] = "";
                    return result;
                }
            } catch(std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }
        }

		void returnVehicle() {
            string licensePlateNum, vehicleType;
            int day, month, year, returnedDay, returnedMonth, returnedYear;
            float mileage;

            cout << "Enter license plate number of vehicle you are returning:" << endl;
            cin >> licensePlateNum;

            cout << "Please enter the day you returned the vehicle: e.g. Enter 18 if date is March 18th" << endl;
            cin >> day;
            cout << "Please enter month you returned the vehicle as a numeral: (January is 01 and so on)" << endl;
            cin >> month;
            cout << "Please enter year you returned the vehicle" << endl;
            cin >> year;
            Date tempActualReturnDate(day, month, year);
            setActualReturnDate(tempActualReturnDate);

            cout << "Enter the type of vehicle you are returning: (car, bike or truck)" << endl;
            cin >> vehicleType;

            cout << "Enter the current mileage on the vehicle you are returning: " << endl;
            cin >> mileage;

            string* rentalInfo = retrieveRentalInfo(licensePlateNum);

            if(rentalInfo[0] == "") {
                cout << "License plate number not found in list for rented vehicles. Try again!" << endl;
            }
            // TODO: Calculate receipt

            // TODO: Update mileage in vehicles file
		}
};
#endif
