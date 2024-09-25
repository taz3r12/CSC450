// Critical_Thinking_Week_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

int main() {
	// Declare three integer variables
	int num1, num2, num3;

	// Prompt user for input
	std::cout << "Enter three integers:\n";
	std::cin >> num1 >> num2 >> num3;

	// Check if input was successful
	if (!std::cin) {
		std::cerr << "Error: Invalid input. Please enter integers only.\n";
		return 1; // Error return code
	}

	// Create pointers to dynamic memory for each integer
	int* ptr1 = new(std::nothrow) int;
	int* ptr2 = new(std::nothrow) int;
	int* ptr3 = new(std::nothrow) int;

	// Check if memory allocation was successful
	if (!ptr1 || !ptr2 || !ptr3) {
		std::cerr << "Error: Memory allocation failed.\n";
		return 2; // Error return code for memory allocation failure
	}

	// Store the values in dynamically allocated memory
	*ptr1 = num1;
	*ptr2 = num2;
	*ptr3 = num3;

	// Display the contents of the variables and pointers
	std::cout << "Values of variables:\n";
	std::cout << "num1: " << num1 << ", num2: " << num2 << ", num3: " << num3 << '\n';

	std::cout << "Values stored in dynamic memory:\n";
	std::cout << "*ptr1: " << *ptr1 << ", *ptr2: " << *ptr2 << ", *ptr3: " << *ptr3 << '\n';

	// Free allocated memory
	delete ptr1;
	delete ptr2;
	delete ptr3;

	// Pause the program to keep the console window open
	std::cout << "Press Enter to exit..." << std::endl;
	std::cin.ignore(); // To ignore any leftover input in the buffer
	std::cin.get();    // Waits for user to press Enter

	return 0;
}
