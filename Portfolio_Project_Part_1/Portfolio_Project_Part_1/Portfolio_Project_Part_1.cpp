// Portfolio_Project_Part_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Mutex to protect shared output
std::mutex mtx;

// Function to count up to 20
void countUp() {
	for (int i = 1; i <= 20; ++i) {
		std::lock_guard<std::mutex> lock(mtx);
		std::cout << "Counting Up: " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
	}
}

// Function to count down from 20 to 0
void countDown() {
	for (int i = 20; i >= 0; --i) {
		std::lock_guard<std::mutex> lock(mtx);
		std::cout << "Counting Down: " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
	}
}

int main() {
	std::cout << "Simple UI: Counting Up and Down with Threads" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	// Create and start the first thread to count up
	std::thread t1(countUp);
	t1.join();  // Wait for the first thread to finish

	// Create and start the second thread to count down
	std::thread t2(countDown);
	t2.join();  // Wait for the second thread to finish

	// Keep the window open until the user presses enter
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Press Enter to exit..." << std::endl;
	std::cin.get();  // Wait for user input (Enter) to close

	return 0;
}

