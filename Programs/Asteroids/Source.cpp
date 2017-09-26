#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "asteroid.h"
#include "ship.h"

void fillVector(vector<Asteroid>&);
// fillVector ==> gets Asteroid information from infile
// @param vector<Asteroid>& - Asteroids in field

void printVector(vector<Asteroid>&);
// printVector ==> prints information about all asteroids
// @param const vector<Asteroid>& ==> Asteroids in field

int main() {
	vector<Asteroid> myAsteroids;

	fillVector(myAsteroids);
	printVector(myAsteroids);

	system("pause");
	return 0;
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
		cout << "Asteroid " << i << "-" << endl;
		cout << "X: " << myAsteroids[i].getXCoord() << ' ';
		cout << "Y: " << myAsteroids[i].getYCoord() << ' ';
		cout << "Weight: " << myAsteroids[i].getWeight() << endl;
	}
}