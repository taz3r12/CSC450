#include "stdafx.h"
#include <iostream>
#include <string>

int main() {
	std::string str1, str2, result;

	// Loop to take input 3 times
	for (int i = 0; i < 3; i++) {
		std::cout << "Enter the first string: ";
		std::getline(std::cin, str1);  // Get the first string input from the user

		std::cout << "Enter the second string: ";
		std::getline(std::cin, str2);  // Get the second string input from the user

		// Concatenate the two strings
		result = str1 + " " + str2;

		// Print the concatenated result
		std::cout << "Concatenated string: " << result << std::endl;
		std::cout << "--------------------------" << std::endl;

		// Wait for the user to press Enter
		std::cout << "Press Enter to continue...";
		std::cin.get();  // Pause for the Enter key
	}

	return 0;
}
