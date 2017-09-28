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
};

Points initiateLaunch();
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
	Points userCoords = initiateLaunch();
	double xShipCoord = userCoords.x;
	double yShipCoord = userCoords.y;
	Ship myShip(xShipCoord, yShipCoord);
	
	fillVector(myAsteroids);
	printVector(myAsteroids);
	system("pause");

	printDashboard(myShip);

	system("pause");
	return 0;
}

Points initiateLaunch() {
	int selection = 0;
	Points xy;
	double x = 0;
	double y = 0;

	cout << "Where would you like to launch your ship?\n";
	cout << "1. Default [0,0]\n";
	cout << "2. User Specified Location\n";
	cout << "Input (1-2): ";
	cin >> selection;

	if (selection == 1) {
		cout << "Default position used ...\n";
		system("pause");
	}
	else if (selection == 2) {
		cout << "Enter coordinates for your ship ...\n";
		cout << "X: "; 
		cin >> x;
		cout << "Y: ";
		cin >> y;

		xy.x = x;
		xy.y = y;
		
		cout << "Ship has launched to coordinates [";
		cout << x << ',' << y << "]\n";
		system("pause");
	}
	else {
		cout << "Invalid selection. Default position used ...\n";
		system("pause");
	}

	return(xy);
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

	cout << setw(60) << setfill('=') << '\n';
	cout << setw(17) << setfill(' ') << left << '|';
	cout << setw(26) << "Ship Information Dashboard";
	cout << setw(17) << right << "|\n";
	cout << setw(13) << left << "| Position: [";
	cout << S.getXCoord() << ',' << S.getYCoord() << ']';
	cout << setw(18) << ' ' << setw(15) << "Hull Weight(Tons): ";
	cout << S.getCollectedWeight();
	cout << setw(5) << right << "|\n";
	cout << setw(10) << left << "| Health: " << S.getShipHealth() << '%';
	cout << setw(21) << ' ' << setw(18) << "Traveled (Miles): ";
	cout << S.getTotalDistance() << setw(6) << right << "|\n";
	cout << setw(60) << setfill('=') << '\n';
}

