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
		void storeRentalInfo(string plateNum) {
			/*
				Stores user rental information to a file
			*/
            try {
                ofstream outFile("rentals.mds", std::ios::app);

                if(outFile.fail()) {
                    throw runtime_error("Cannot access file");
                }

                outFile << plateNum << "\t" << getCustomerName() << "\t" << getHomeAddress() << "\t" << getPhoneNumber() << "\t" << getDateRented() << "\t"
                        << getExpectedReturnDate() << "\t" << getDepositPaid() << endl;

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
            string plateNum, tempName, tempAddress, tempPhoneNumber, today, returnDate;
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

            cout << "Please enter today's date in the format (dd-mm-yyyy):" << endl;
            cin >> today;
            setDateRented(today);

            cout << "Please enter the date you will return the vehicle in the format (dd-mm-yyyy):" << endl;
            cin >> returnDate;
            setDateRented(returnDate);

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
		
		void searchVehicles(string searchCriteria) {
			/* Allow the user to search for a vehicle based on anyone of the following criteria:
                    1. license plate number
                    2. brand
                    3. model
                    4. year
                    5. interior
            */

		}
		
		void showRentals(int searchId) {
    		/*
    		 *
    		 * Show all the vehicles the user has rented
    		 *
            */


		}
		
		void returnVehicle(string licensePlateNumber) {

		}
};
#endif
