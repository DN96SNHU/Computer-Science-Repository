//Dave Necrason
//CS-210 Project three
//April 17, 2026
//Implementation file for GroceryTracker class. Contains constructor that reads input file and counts items, and three menu option functions for getting item frequency, printing frequencies, and printing a histogram.


#include "groceryH.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Constructor that opens the input file, counts each item and wirtes frquency.dat file.

GroceryTracker::GroceryTracker() {
	ifstream inputFile;
	ofstream outputFile;
	string item;
	//Open the input file and check for errors
	inputFile.open("CS210_Project_Three_Input_File.txt");

	if (!inputFile) {
		cout << "Error: could not open input file." << endl;
		exit(EXIT_FAILURE);
	}
	//Reads each item and increment its count in the map
	//map auto initiazes new keys to 0
	while (getline(inputFile, item)) {
		grocList[item]++;
	}


	inputFile.close(); //closes input file

	//writes all data to frequency.dat
	outputFile.open("frequency.dat");

	if (!outputFile) {
		cout << "Error: could not open output file." << endl;
		exit(EXIT_FAILURE);
	}

	for (auto& entry : grocList) {
		outputFile << entry.first << " " << entry.second << endl;
	}

	outputFile.close(); //closes output file
}

//Menu option 1: returns the frequency of the specified item, if it exists in the map, otherwise returns 0.
int GroceryTracker::getItemFrequency(string item) {
	int frequency = 0;

	if (grocList.count(item)) {
		frequency = grocList[item];
	}

	return frequency;
}
//Menu option 2: prints each item and its frequency to the console.
void GroceryTracker::printFrequencies() {
	for (auto& entry : grocList) {
		cout << entry.first << " " << entry.second << endl;
	}
}
//Menu option 3: prints a histogram of items and their frequencies using asterisks.
void GroceryTracker::printHistogram() {
	int numStars = 0;
	for (auto& entry : grocList) {
		numStars = entry.second;
		cout << entry.first << " " << string(numStars, '*') << endl;
	}
}