#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

string initFiles(string);
void initQueue(List<int>&, string);

int main() {
	List<int> L;
	string infileName;

	infileName = initFiles(infileName);
	initQueue(L, infileName);

	L.print();

	system("pause");
	return 0;
}

string initFiles(string infileName) {
beginning:				// Create breakpoint
	int selection;
	ifstream infile;
	ofstream outfile;
	outfile.open("output.txt", ios::trunc);

	cout << "Priority Queue w/ Teams\nCoded By: Brice Allard\n\n";
	outfile << "Priority Queue w/ Teams\nCoded By: Brice Allard\n\n";

	cout << "Use Default or Custom Infile?\n";
	cout << "1. Default\n2. Custom\n(1-2): ";
	cin >> selection;

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
			goto beginning;
		}
	}
	else {
		cout << "\nEnter a Valid Option ...\n\n";
		system("pause");
		system("CLS");
		goto beginning;
	}

	infile.close();
	outfile.close();

	return infileName;
}

void initQueue(List<int>& L, string infileName) {
	ifstream infile;
	ofstream output;
	infile.open(infileName);
	output.open("output.txt", ios::app);

	int numTeams, totMembers, teamNum;
	string toDo;

	infile >> numTeams;

	while (numTeams != 0) {
		infile >> totMembers;

		int** teams = new int*[numTeams];

		for (int i = 0; i < numTeams; i++)
			teams[i] = new int[totMembers];

		for (int i = 0; i < numTeams; i++) {
			for (int j = 0; j < totMembers; j++) {
				infile >> teamNum;
				teams[i][j] = teamNum;
			}
			infile >> totMembers;
		}

		//string line;
		//while (getline(infile, line)) {
		//	stringstream line_stream(line);

		//	if (line_stream >> toDo >> teamNum) {
		//		cout << "READ '" << toDo << "' from input.\n";
		//	}
		//}

		infile >> toDo >> teamNum;
		cout << "READ '" << toDo << "' from input.\n";

		if (toDo == "STOP")
			return;
		if (toDo == "ENQUEUE") {
			
			for (int i = 0; i < numTeams; i++) {
				for (int j = 0; j < totMembers; j++) {
					if (teams[i][j] == teamNum) {
						L.insert(teamNum, i + 1);
					}
				}
				infile >> totMembers;
			}
		}
		infile >> numTeams;
	}
}
