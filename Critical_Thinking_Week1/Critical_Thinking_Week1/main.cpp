#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare variables
	string firstName = "John";
	string lastName = "Doe";
	string streetAddress = "1234 Elm Street";
	string city = "Metropolis";
	string zipCode = "12345";

	// Print the information
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Street Address: " << streetAddress << endl;
	cout << "City: " << city << endl;
	cout << "Zip Code: " << zipCode << endl;

	// Wait for user input to close the program
	cout << "Press Enter to exit..." << endl;
	cin.get();

	return 0;
}