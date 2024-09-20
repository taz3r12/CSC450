#include "stdafx.h"  // Only if precompiled headers are used
#include <iostream>  // For input/output stream
#include <conio.h>   // For _getch()

using namespace std;  // Standard namespace declaration

int main()
{
	double myMoney = 1000.50;  // This should be printed out

	// Standard Output Statement
	cout << "Please be sure to correct all syntax errors in this program" << endl;

	cout << "I have corrected all errors for this program." << endl;

	// Printing out the value of myMoney
	cout << "The total amount of money available is = " << myMoney << endl;

	// Wait for user input to keep the console window open
	cout << "Press any key to exit..." << endl;
	_getch();  // Wait for key press (from <conio.h>)

	// Main function return statement
	return 0;
}