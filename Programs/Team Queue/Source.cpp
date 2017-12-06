/*
Brice Allard
Program 5 - Team Queue
Dr. Stringfellow

Team Queue is similiar to a standard queue however it
implements a priority based list that inserts higher priority
items before lower priority. In this case, team 1 > team 2 > team 3.

** Ability to use standard queue implementation is possible by
	changing all L.Insert() to L.Enqueue().
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"

using namespace std;

string initFiles();
// initFiles ==> initiates and opens files based on user input
// @param string - name of the inputfile

void initQueue(List<int>&, string);
// initQueue ==> creates teams and enters them into queue
// @param List<T>& - List (queue) pass by reference where data stored
//			string - infile name to read data from

int main() {
	// Initialize Variables
	List<int> L;
	string infileName;

	//Gather user data for input files
	infileName = initFiles();

	//Begin reading data and organizing queues
	initQueue(L, infileName);

	// All done
	system("pause");
	return 0;
}

/*
// initiates and opens files based on user input
// @param string - name of the inputfile
*/
string initFiles() {
beginning:				// Create breakpoint
	// initialize variables
	int selection;
	string infileName;

	// create & open I/O files
	ifstream infile;
	ofstream outfile;
	outfile.open("output.txt", ios::trunc);

	cout << "Priority Queue w/ Teams\nCoded By: Brice Allard\n\n";
	outfile << "Priority Queue w/ Teams\nCoded By: Brice Allard\n\n";

	cout << "Use Default or Custom Infile?\n";
	cout << "1. Default\n2. Custom\n(1-2): ";
	cin >> selection;

	// Default file
	if (selection == 1) {
		infileName = "prog5data.txt";
		infile.open(infileName);

		if (infile)
			cout << "\nDefault Input File Selected (prog5data.txt)...\n\n";
		else {
			cout << "\nDefault Input File Failed to Load ... \n\n";
			system("pause");
			system("CLS");
			goto beginning;			// Try again ...
		}
	}
	// User defined file name
	else if (selection == 2) {
		cout << "\nType Name of Input File (ex. inputfile.txt):\n";
		cin.ignore();
		getline(cin, infileName);
		infile.open(infileName);

		if (infile)
			cout << "\nCustom Input File Selected (" << infileName << ")\n\n";
		else {
			cout << "\nCustom Input File Failed to Load ... \n\n";
			system("pause");
			system("CLS");
			goto beginning;			// Try again ...
		}
	}
	// Incorrect input. User error ... 
	else {
		cout << "\nEnter a Valid Option ...\n\n";
		system("pause");
		system("CLS");
		goto beginning;				// Try again ...
	}

	// Close all files
	infile.close();
	outfile.close();

	return infileName;
}

/*
// creates teams and enters them into queue
// @param List<T>& - List (queue) pass by reference where data stored
//			string - infile name to read data from
*/
void initQueue(List<int>& L, string infileName) {
	// open I/O files
	ifstream infile;
	ofstream outfile;
	infile.open(infileName);
	outfile.open("output.txt", ios::app);

	// Initialize Member Variables
	int numTeams, totMembers, teamNum;
	int scenario = 1;
	string toDo;

	// Begin read
	infile >> numTeams;

	// Declare 2D array to store member data in
	// [a][b] ==> a is team -> b is member number
	int** teams = new int*[numTeams];

	// Delimiter set to int(0) ==> (will end reading from file)
	while (numTeams != 0) {
		outfile << "Scenario #" << scenario << ":\n";
		cout << "Press enter to begin Scenario #" << scenario << '\n';
		system("pause");
		system("CLS");
		cout << "Scenario #" << scenario << "\n\n";
		cout << " - Teams Created - \n";

		// Set size of 2D array
		for (int i = 0; i < numTeams; i++) {
			infile >> totMembers;
			teams[i] = new int[totMembers];
			cout << "Team " << i + 1 << ": ";

			// Assign member data to 2D array
			for (int j = 0; j < totMembers; j++) {
				infile >> teamNum;
				teams[i][j] = teamNum;
				cout << teamNum << ' ';
			}
			cout << endl;
		}

		cout << endl;
		infile >> toDo;

		// Continue until second delimiter str("STOP") is found
		while (toDo != "STOP") {
			if (toDo == "ENQUEUE") {
				infile >> teamNum;

				// Search list for team member number - O(n)
				for (int i = 0; i < numTeams; i++) {
					for (int j = 0; j < totMembers; j++) {
						if (teams[i][j] == teamNum) {
							L.insert(teamNum, i + 1);
						}
					}
				}
			}
			else if (toDo == "DEQUEUE") {
				// set dequeue item being removed
				int data = L.deque();
				
				// if data found
				if(data != -1)
					outfile << data << endl;
			}

			infile >> toDo;		// start over (check for "STOP" delimiter)
		}
		// End of scenario updates, begin fresh for next scenario or end prog.
		infile >> numTeams;

		// Clear all items from queue for next scenario
		L.deleteAll();
		cout << "\nEnd of Scenario #" << scenario << " ...\n\n";
		scenario++;
	}
}
