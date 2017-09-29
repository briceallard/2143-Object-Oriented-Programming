#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "asteroid.h"
#include "ship.h"

using namespace std;

struct Points {
	double x;
	double y;
	int asteroids;
};

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

int main() {
	vector<Asteroid> myAsteroids;
	fillVector(myAsteroids);

	Points userCoords = initiateLaunch(myAsteroids);
	double xShipCoord = userCoords.x;
	double yShipCoord = userCoords.y;
	unsigned int numToCollect = userCoords.asteroids;
	Ship myShip(xShipCoord, yShipCoord);

	for (unsigned int i = 0; i < numToCollect; i++) {
		printDashboard(myShip);
		myShip.findAsteroid(myAsteroids);
	}

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

	cout << "--- SpaceAsteroid, Inc ---\n\n--- Initializing radar ---\n\n";
	cout << "Radar has located " << maxAsteroids 
		<< " asteroids in your current solar system.\n";
	cout << "How many would you like to mine today Captain?\n";
	cout << "Input (1-" << maxAsteroids << "): ";
	cin >> userCollects;
	cout << "\nWhere would you like to launch your ship?\n";
	cout << "1. Default [0,0]\n";
	cout << "2. User Specified Location\n";
	cout << "Input (1-2): ";
	cin >> selection;
	cout << '\n';

	if (selection == 1) {
		xyz.x = x;
		xyz.y = y;
		xyz.asteroids = userCollects;

		cout << "Default coordinates entered into navigation.\n";
		cout << "Press Enter to launch and begin mining expidition ...\n\n";
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
		xyz.asteroids = userCollects;

		cout << '[' << x << ',' << y 
			<< "] coordinates entered into navigation.\n";
		cout << "Press Enter to launch and begin mining expidition ...\n\n";
		system("pause");
	}
	else {
		xyz.x = x;
		xyz.y = y;
		xyz.asteroids = userCollects;

		cout << "Invalid selection!";
		cout << "Default coordinates entered into navigation.\n";
		cout << "Press Enter to launch and begin mining expidition ...\n\n";
		system("pause");
	}

	return(xyz);
}

void fillVector(vector<Asteroid>& newMyAsteroids) {
	double x;
	double y;
	double weight;

	ifstream infile;
	infile.open("input.txt");

	infile >> x >> y >> weight;

	while (!infile.eof()) {
		Asteroid newAsteroid(x, y, weight);
		newMyAsteroids.push_back(newAsteroid);

		infile >> x >> y >> weight;
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
	cout << setw(26) << "Ship Information Dashboard" << '\n';
	cout << setw(2) << ' ';
	cout << setw(10) << left << "Position: ";
	cout << setw(9) << left << '[' << S.getXCoord()
		<< ','<< S.getYCoord() << ']';
	cout << setw(8) << ' ';
	cout << setw(19) << left << "Hull Weight(Tons): ";
	cout << setw(10) << S.getCollectedWeight() << '\n';
	cout << setw(2) << ' ';
	cout << setw(10) << left << "Health: " << S.getShipHealth() << '%';
	cout << setw(15) << ' ';
	cout << setw(18) << "Traveled (Miles): " << S.getTotalDistance()
		<< '\n';
	cout << "===========================================================\n";

}