//Dave Necrason
//CS-210 Project three
//April 17, 2026
//Header file for GroceryTracker class. Contains constructor that reads input file and counts items, and three menu option functions for getting item frequency, printing frequencies, and printing a histogram.

#ifndef GROCERY_H
#define GROCERY_H

#include <string>
#include <map>

using namespace std;

class  GroceryTracker {
public:
	//Constructor that reads input file, builds frequency map, and writes frequency.dat file.
	GroceryTracker();
	//Menu option 1
	int getItemFrequency(string item);
	//Menu option 2
	void printFrequencies();
	//Menu option 3
	void printHistogram();

private:
	map<string, int> grocList; // ordererd map to store grocery items and their frequencies
};

#endif