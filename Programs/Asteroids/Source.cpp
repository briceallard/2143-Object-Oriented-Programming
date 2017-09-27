#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "asteroid.h"
#include "ship.h"

using namespace std;

void fillVector(vector<Asteroid>&);
// fillVector ==> gets Asteroid information from infile
// @param vector<Asteroid>& - Asteroids in field

void printVector(vector<Asteroid>&);
// printVector ==> prints information about all asteroids
// @param const vector<Asteroid>& ==> Asteroids in field

void printDashboard();
// printDashboard ==> prints header with ship information

int main() {
	vector<Asteroid> myAsteroids;

	fillVector(myAsteroids);
	printVector(myAsteroids);
	system("pause");

	printDashboard();

	system("pause");
	return 0;
}

// Just testing a menu style information header (NOT COMPLETE YET)
void printDashboard() {
	system("CLS");

	cout << "======================================================\n"
		<< "|            Ship Information Dashboard              |\n"
		<< "| Position: [x,y]          Hull Weight(Tons): 12     |\n"
		<< "| Health: 100%             Traveled (Miles): ~4.2k   |\n"
		<< "======================================================\n";
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
