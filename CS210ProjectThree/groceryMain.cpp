//Dave Necrason
//CS-210 Project three
//April 17, 2026
//Main file for grocery tracker program. Contains main function and utility functions for input validation, screen clearing, and pausing.
#include "groceryH.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//The following prompts a user to input an int between min and max, if input is bad it re-prompts.

int getInteger(int min, int max, string prompt) {
	int value = 0; //stores input
	bool valid = false; // determines if valid input was received

	while (!valid) { //loop runs while valid input is not received
		cout << prompt;
		cin >> value;

		if (cin.fail() || value < min || value > max) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Must be integer between " << min << " and " << max << "." << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer
			valid = true;
		}
	}
	return value;
}
//Pauses screen until user presses enter key.
void pauseScreen() {
	cout << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//function for clearnig the console screen. Should work on Windows and Linux/MacOS systems.
void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main() {
	GroceryTracker tracker; //tracker object that reads file and writes frequency.dat
	int selection = 0; //stores menu choice
	string searchItem; //stores item entered by user for option 1
	int frequency = 0; //stores frequency result from option 1

	// Main loop runs until user selects 4
	while (selection != 4) {
		cout << "Press 1 to find an item" << endl;
		cout << "Press 2 to list items and quantities" << endl;
		cout << "Press 3 to print histogram" << endl;
		cout << "Press 4 to exit" << endl;

		selection = getInteger(1, 4, "Please select menu option 1 thorugh 4 : ");
		//Item look up option prompts item name, displays frequency if found, otherwise displays not found message.
		if (selection == 1) {
			cout << "Enter the item you want to look up: ";
			getline(cin, searchItem);

			frequency = tracker.getItemFrequency(searchItem);

			if (frequency > 0) {
				cout << searchItem << " was purchased " << frequency << " time(s)." << endl;

			}
			else {
				cout << searchItem << " was not found in today's record." << endl;

			}
			pauseScreen();
			clearScreen();
		}
		//Option 2 and 3 both print all items and frequencies, but option 3 also prints a histogram of asterisks.
		else if (selection == 2) {
			cout << endl;
			tracker.printFrequencies();
			pauseScreen();
			clearScreen();
		}
		else if (selection == 3) {
			cout << endl;
			tracker.printHistogram();
			pauseScreen();
			clearScreen();
		}
	}
	cout << "Goodbye!" << endl; //Exit message

	return 0;
}