//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Dave Necrason
// Description : Second project for CS 300
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

// This stores relevant info for a course

struct Course {
	string courseNumber;
	string name;
	vector<string> prerequisites; //List of prereq course numbers
};

//One node in binary search tree
struct TreeNode {
	Course course;
	TreeNode* left;
	TreeNode* right;
	TreeNode(Course c) : course(c), left(nullptr), right(nullptr) {}
};

//Splits comma-separated string into trimmed tokens
vector<string> tokenize(const string& line) {
	vector<string> tokens;
	stringstream ss(line);
	string token;
	while (getline(ss, token, ',')) {
		size_t start = token.find_first_not_of(" \t\r\n");
		size_t end = token.find_last_not_of(" \t\r\n)");
		if (start != string::npos) {
			tokens.push_back(token.substr(start, end - start + 1));
		}
	}
	return tokens;
}

//Converts string to uppercase in place
void toUpperCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}

//Inserts course into BST based on course number, recursively
void insert(TreeNode*& node, const Course& course) {
	if (node == nullptr) {
		node = new TreeNode(course);
		return;
	}
	if (course.courseNumber < node->course.courseNumber) {
		insert(node->left, course);
	}
	else {
		insert(node->right, course);
	}
}

//Returns pointer to matching course. Nullptr if not found.
Course* search(TreeNode* node, const string& courseNumber) {
	if (node == nullptr) return nullptr;
	if (courseNumber == node->course.courseNumber) return &node->course;
	if (courseNumber < node->course.courseNumber) return search(node->left, courseNumber);
	return search(node->right, courseNumber);
}

//Loads and validates course data from CSV file, building BST.
bool loadCourses(const string& fileName, TreeNode*& root) {
	ifstream file(fileName);
	if (!file.is_open()) {
		cout << "Error: could not open \"" << fileName << "\". Please check the file name and try again." << endl;
		return false;
	}

	//First pass, collects course numbers to validate prerequisites
	vector<string> courseNumbers;
	string line;
	while (getline(file, line)) {
		vector<string> tokens = tokenize(line);
		if (tokens.size() < 2) {
			cout << "Warning: skipping malformed line - fewer than 2 fields." << endl;
			continue;
		}
		string cn = tokens[0];
		toUpperCase(cn);
		courseNumbers.push_back(cn);
	}

	//Second pass, build each course and insert valid courses into BST
	file.clear();
	file.seekg(0);
	while (getline(file, line)) {
		vector<string> tokens = tokenize(line);
		if (tokens.size() < 2) continue;
		Course course;
		course.courseNumber = tokens[0];
		toUpperCase(course.courseNumber);
		course.name = tokens[1];
		bool valid = true;

		for (size_t i = 2; i < tokens.size(); ++i) {
			string prereq = tokens[i];
			toUpperCase(prereq);
			//Validate prereq exists in courseNumbers
			bool found = false;
			for (const string& cn : courseNumbers) {
				if (cn == prereq) {
					found = true; break;
				}
			}
			if (!found) {
				cout << "Error: prerequisite \"" << tokens[i] << "\" for course "
					<< tokens[0] << " not found - skipping this course." << endl;
				valid = false;
				break;
			}
			course.prerequisites.push_back(prereq);
		}

		if (valid) insert(root, course);
	}
	file.close();
}

//In order traversal thgat prints course info in alphanumeric order
void printAllCourses(TreeNode* node) {
	if (node == nullptr) return;
	printAllCourses(node->left);
	cout << node->course.courseNumber << ", " << node->course.name << endl;
	printAllCourses(node->right);

}

//Look up a course and print title and prereqs
void printCourseInformation(TreeNode* root, const string& courseNumber) {
	Course* course = search(root, courseNumber);
	if (course == nullptr) {
		cout << "Course " << courseNumber << " not found." << endl;
		return;
	}

	cout << course->courseNumber << ", " << course->name << endl;

	if (course->prerequisites.empty()) {
		cout << "Prerequisites: None" << endl;
	}
	//Print prereqs separated by commas
	else {
		cout << "Prerequisites: ";
		for (size_t i = 0; i < course->prerequisites.size(); ++i) {
			if (i > 0) cout << ", ";
			cout << course->prerequisites[i];
		}
		cout << endl;
	}
}

int main() {
	TreeNode* courseTree = nullptr;
	bool dataLoaded = false;
	int choice = 0;

	cout << "Welcome to the course planner." << endl;

	while (choice != 9) {
		cout << endl;
		cout << "	1. Load Data Structure." << endl;
		cout << "	2. Print Course List." << endl;
		cout << "	3. Print Course." << endl;
		cout << "	9. Exit." << endl;
		cout << endl;
		cout << "What would you like to do? ";

		//Handles invalid non integer input
		if (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}
		switch (choice) {
		case 1: {
			string fileName;
			cout << "Enter the file name: ";
			cin >> fileName;
			if (loadCourses(fileName, courseTree)) {
				dataLoaded = true;
				cout << "Courses loaded successfully!" << endl;
			}
			break;
		}
		case 2:
			if (!dataLoaded) {
				cout << "Please load data first (Option 1)." << endl;
			}
			else {
				cout << "Here is a sample schedule:" << endl << endl;
				printAllCourses(courseTree);
			}
			break;
		case 3:
			if (!dataLoaded) {
				cout << "Please load data first (Option 1)." << endl;
			}
			else {
				string courseNumber;
				cout << "What course do you want to know about? ";
				cin >> courseNumber;
				toUpperCase(courseNumber);
				printCourseInformation(courseTree, courseNumber);
			}
			break;

		case 9:
			cout << "Thank you for using the course planner!" << endl;
			break;
		default:
			cout << choice << " is not a valid option." << endl;
			break;
		}
	}
	return 0;
}
				
