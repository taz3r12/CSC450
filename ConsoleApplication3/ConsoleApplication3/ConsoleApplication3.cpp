// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to reverse the contents of a file and write it to another file
void reverseFileContents(const std::string& inputFile, const std::string& outputFile) {
	// Open the input file for reading
	std::ifstream inFile(inputFile);

	// Check if the input file was opened successfully
	if (!inFile) {
		std::cerr << "Error: Could not open " << inputFile << " for reading." << std::endl;
		return;
	}

	// Read the entire content of the input file into a string
	std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

	// Close the input file
	inFile.close();

	// Reverse the content
	std::reverse(content.begin(), content.end());

	// Open the output file for writing
	std::ofstream outFile(outputFile);

	// Check if the output file was opened successfully
	if (!outFile) {
		std::cerr << "Error: Could not open " << outputFile << " for writing." << std::endl;
		return;
	}

	// Write the reversed content to the output file
	outFile << content;

	// Close the output file
	outFile.close();
}

int main() {
	std::string inputFile = "CSC450_CT5_mod5.txt";
	std::string reversedFile = "CSC450-mod5-reverse.txt";
	std::string userInput;

	// Get input from the user
	std::cout << "Enter text to append to the file: ";
	std::getline(std::cin, userInput);

	// Open the file in append mode
	std::ofstream file(inputFile, std::ios::app);

	// Check if the file opened successfully
	if (!file) {
		std::cerr << "Error: Could not open " << inputFile << " for writing." << std::endl;
		return 1;
	}

	// Append the user's input to the file
	file << userInput << std::endl;

	// Close the file
	file.close();

	// Reverse the contents of the file and store it in another file
	reverseFileContents(inputFile, reversedFile);

	std::cout << "User input appended to " << inputFile << "." << std::endl;
	std::cout << "Reversed contents stored in " << reversedFile << "." << std::endl;

	return 0;
}
