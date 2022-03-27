#include <iostream>
#include <string>
#include "User.h"
#include "Car.h"
#include "truck.h"
#include "Bike.h"

using namespace std;

void populateFiles() {
    // Cars
    Car c1("7665BG", "Honda", "Fit", "2014", "Blue", 1.5f, "Gas", "CVT", 38941.0f, 5, 11000.0f, "no", "Leather");
    c1.storeVehicle();

    // Trucks
    Truck t1("8967PO", "Toyota", "Hilux", "2018", "Orange", 2.4f, "Diesel", "M", 57542.0f, 3, 25000.f, "no", "Nylon", 750);
    t1.storeVehicle();

    // Bikes
    Bike b1("7950HI", "Yamaha", "YZF R1", "2018", "Blue", 1.0f, "Gas", "M", 3532.f, 2, 7000.0f, "no", 1);
    b1.storeVehicle();
}


int main(int argc, char** argv) {
    populateFiles();
	User user;
	int choice;
	string searchCriteria;
	int searchId;
	string licensePlateNum;
	
	cout << "\t------ Welcome to Cars4Rent ------\n\n" << endl;
	cout << "1. View vehicles\n2. Search vehicles\n3. Show Rentals\n4. Return vehicle" << endl;
	cout << "Choose number corresponding to option: " << endl;
	cin >> choice;
	
	switch(choice) {
		case 1:
			user.viewVehicles();
			break;
		case 2:
			cout << "Enter search criteria:" << endl;
			cin >> searchCriteria;
			user.searchVehicles(searchCriteria);
			break;
		case 3:
			cout << "Enter your id:" << endl;
			cin >> searchId;
			user.showRentals(searchId);
			break;
		case 4:
			cout << "Enter license plate number of vehicle you are returning:" << endl;
			cin >> licensePlateNum;
			user.returnVehicle(licensePlateNum);
			break;
		default:
			cout << "Option not recognized!" << endl;
	}
	return 0;
}
