#include <iostream>
#include <string>
#include "User.h"

using namespace std;


int main(int argc, char** argv) {
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
