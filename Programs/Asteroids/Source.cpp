#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include "asteroid.h"
#include "ship.h"

using namespace std;

struct Points {
	double x;
	double y;
	int asteroids;
};

void delay(double, int);
// delay ==> pause with a '.' every second for output

Points initiateLaunch(vector<Asteroid>&);
// initiateLaunch ==> gets user input and establishes ship
//						launch location

void fillVector(vector<Asteroid>&);
// fillVector ==> gets Asteroid information from infile
// @param vector<Asteroid>& - Asteroids in field

void printVector(vector<Asteroid>&);
// printVector ==> prints information about all asteroids
// @param const vector<Asteroid>& ==> Asteroids in field

void printDashboard(Ship);
// printDashboard ==> prints header with ship information

void outfileHeader(ofstream&);

void outfileTotals(vector<Asteroid>&, Ship, ofstream&);
// outfilePrint ==> outputs the mining data to outfile.txt
// @param const vector<Asteroid>& ==> Asteroids in field
// @param Ship ==> ship data
// @param ofstream& ==> outfile to write too

void outfileTotals(vector<Asteroid>&, Ship, ofstream&);

int main() {
	vector<Asteroid> myAsteroids;
	fillVector(myAsteroids);

	ofstream outfile;
	outfile.open("output.txt");
	outfileHeader(outfile);

	Points userCoords = initiateLaunch(myAsteroids);
	double xShipCoord = userCoords.x;
	double yShipCoord = userCoords.y;
	unsigned int numToCollect = userCoords.asteroids;
	Ship myShip(xShipCoord, yShipCoord);

	for (unsigned int i = 0; i < numToCollect; i++) {
		printDashboard(myShip);
		myShip.findAsteroid(myAsteroids, outfile);
	}

	outfileTotals(myAsteroids, myShip, outfile);
	system("pause");
	return 0;
}

Points initiateLaunch(vector<Asteroid>& myAsteroids) {
	Points xyz;
	double x = 0;
	double y = 0;
	int userCollects = 0;
	int selection = 0;
	unsigned int maxAsteroids = myAsteroids.size();

	cout << "--- SpaceAsteroid, Inc ---\n\n";
	cout << "Analyzing system data";
	//delay(1, 3);
	cout << "Initializing radar";
	//delay(1, 3);
	cout << "Entering hyper-space";
	//delay(1, 3);
	cout << "\nWelcome, Captain!\n";
	cout << "Where would you like to mine today?\n";
	cout << "1. Default [0,0]\n";
	cout << "2. Specify Location\n";
	cout << "Input (1-2): ";
	cin >> selection;
	cout << '\n';

	if (selection == 1) {
		xyz.x = x;
		xyz.y = y;

		cout << "Default coordinates entered into navigation.\n";
		cout << "Press Enter to make hyper-jump and begin mining "
			<< "expidition ...\n\n";
		system("pause");
	}
	else if (selection == 2) {
		cout << "Enter coordinates for your ship ...\n";
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		cout << '\n';

		xyz.x = x;
		xyz.y = y;

		cout << '[' << x << ',' << y
			<< "] coordinates entered into navigation.\n";
		cout << "Press Enter to make hyper-jump and begin mining "
			<< "expidition ...\n\n";
		system("pause");
	}
	else {
		xyz.x = x;
		xyz.y = y;

		cout << "Invalid selection!\n";
		cout << "Default coordinates entered into navigation.\n";
		cout << "Press Enter to make hyper-jump and begin mining "
			<< "expidition ...\n\n";
		system("pause");
	}

	cout << "\nScanning environment";
	//delay(1, 5);
	cout << "\nRadar has located " << maxAsteroids
		<< " asteroids in your current solar system.\n";
	cout << "How many would you like to mine today Captain?\n";
	cout << "Input (1-" << maxAsteroids << "): ";
	cin >> userCollects;
	xyz.asteroids = userCollects;

	cout << "\nPress enter to begin mining ";

	return(xyz);
}

void delay(double time, int loop) {
	double timer = time * 1000;

	for (unsigned int i = 0; i < loop; i++) {
		cout.flush();
		Sleep(timer);
		cout << ". ";
	}
	cout << "DONE!" << endl;
	cout.flush();
}

void fillVector(vector<Asteroid>& newMyAsteroids) {
	double x;
	double y;
	double weight;
	int index = 1;

	ifstream infile;
	infile.open("input.txt");

	infile >> x >> y >> weight;

	while (!infile.eof()) {
		Asteroid newAsteroid(x, y, weight, index);
		newMyAsteroids.push_back(newAsteroid);

		infile >> x >> y >> weight;
		index++;
	}
}

void printVector(vector<Asteroid>& myAsteroids) {
	unsigned int size = myAsteroids.size();

	for (unsigned int i = 0; i < size; i++) {
		cout << "Asteroid " << i + 1 << "- \n";
		cout << "X: " << myAsteroids[i].getXCoord() << ' ';
		cout << "Y: " << myAsteroids[i].getYCoord() << ' ';
		cout << "Weight: " << myAsteroids[i].getWeight() << '\n';
	}
}

void printDashboard(Ship S) {
	system("CLS");	//Clear screen to give effect of immediate update

	cout << "===========================================================\n";
	cout << setw(17) << ' ';
	cout << setw(26) << "Ship Information Dashboard" << "\n";
	cout << setw(2) << ' ';
	cout << setw(20) << left << "--Current Position--";
	cout << setw(20) << ' ';
	cout << setw(19) << "--Ship Status--\n";
	cout << setw(4) << ' ';
	cout << setw(1) << left << '[' << S.getXCoord()
		<< ',' << S.getYCoord() << ']';
	cout << setw(20) << ' ';
	cout << setw(17) << right << S.getShipHealth() << "%\n\n";
	cout << setw(2) << ' ';
	cout << setw(20) << left << "--Hull Weight(Tons)--";
	cout << setw(13) << ' ';
	cout << setw(20) << "--Distance Traveled--\n";
	cout << setw(9) << ' ';
	cout << setw(24) << S.getCollectedWeight();
	cout << setw(20) << right << S.getTotalDistance() << "km\n";
	cout << "===========================================================\n";
}

void outfileHeader(ofstream& outfile) {
	outfile << "Brice Allard\n";
	outfile << "2143 - OOP\n";
	outfile << "Dr. Stringfellow\n";
	outfile << "Program 2 - Asterodis\n\n";

	outfile << setw(44) << right << "Mission Status Report\n";
	outfile << setw(70) << setfill('-') << '\n';
	outfile << setfill(' ') << setw(20) << left << "Asteroid Collected";
	outfile << setw(10) << left << "Position";
	outfile << setw(10) << right << "Weight";
	outfile << setw(29) << right << "Distance (miles)" << endl;
}

void outfileTotals(vector<Asteroid>& myAsteroids, Ship S, ofstream& outfile) {
	outfile << setw(70) << setfill('-') << '\n';
	outfile << setfill(' ') << setw(10) << right << myAsteroids.size();
	outfile << setw(15) << right << '-';
	outfile << setw(14) << right << S.getCollectedWeight();
	outfile << setw(25) << right << S.getTotalDistance() << endl;
}