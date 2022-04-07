/*	Object Oriented Programming

	Object Oriented Programming Project

	C++ Driver File

	Tutor : Mr. Tyrone Edwards

	Group Members : Taje Thomas-1903700
					Rajae Robinson- 2006677
					Subrina Powise-
					Joshua Barett-
*/
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
    Truck t1("8967P0", "Toyota", "Hilux", "2018", "Orange", 2.4f, "Diesel", "M", 57542.0f, 3, 25000.f, "no", "Nylon", 750);
    t1.storeVehicle();

    // Bikes
    Bike b1("7950HI", "Yamaha", "YZF R1", "2018", "Blue", 1.0f, "Gas", "M", 3532.f, 2, 7000.0f, "no", 1);
    b1.storeVehicle();
}


int main(int argc, char** argv) {
    populateFiles();
	User user;
	int choice;
	
	cout << "\t------ Welcome to Cars4Rent ------\n\n" << endl;
	cout << "1. View vehicles\n2. Search vehicles\n3. Show Rentals\n4. Return vehicle" << endl;
	cout << "Choose number corresponding to option: " << endl;
	cin >> choice;
	
	switch(choice) {
		case 1:
			user.viewVehicles();
			break;
        case 2:
			user.searchVehicles();
			break;
        case 3:
			user.showRentals();
			break;
		case 4:
			user.returnVehicle();
			break;
		default:
			cout << "Option not recognized!" << endl;
	}
	return 0;
}
