#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <vector>
#include "ship.h"
#include "asteroid.h"

using namespace std;

Ship::Ship() {
	totWeight = 0;
	totDistance = 0;
	shipXCoord = 0;
	shipYCoord = 0;
	shipHealth = 100;
}

Ship::Ship(double x, double y) {
	totWeight = 0;
	totDistance = 0;
	shipXCoord = x;
	shipYCoord = y;
	shipHealth = 100;
}

Ship::~Ship() {

}

double Ship::getCollectedWeight() {
	return totWeight;
}

double Ship::getTotalDistance() {
	return totDistance;
}

double Ship::getShipHealth() {
	return shipHealth;
}

double Ship::getXCoord() {
	return shipXCoord;
}

double Ship::getYCoord() {
	return shipYCoord;
}

void Ship::setXCoord(double x) {
	shipXCoord = x;
}

void Ship::setYCoord(double y) {
	shipYCoord = y;
}

void Ship::findAsteroid(vector<Asteroid>& myAsteroids, ofstream& outfile) {
	unsigned int size = myAsteroids.size();
	double asteroidX;
	double asteroidY;
	int closestIndex = 0;
	int selection = 0;
	double closestDistance = DBL_MAX;

	for (unsigned int i = 0; i < size; i++) {
		double distance = 0;

		asteroidX = myAsteroids[i].getXCoord();
		asteroidY = myAsteroids[i].getYCoord();

		distance = sqrt(pow((asteroidX - getXCoord()), 2)
			+ pow((asteroidY - getYCoord()), 2));
		
		if (!myAsteroids[i].isCollected() && distance < closestDistance) {
			closestIndex = i;
			closestDistance = distance;
		}
	}

	asteroidX = myAsteroids[closestIndex].getXCoord();
	asteroidY = myAsteroids[closestIndex].getYCoord();

	if (myAsteroids[closestIndex].isTooBig() && !myAsteroids[closestIndex].isCollected()) {
		cout << "Asteroid " << closestIndex + 1 << " is the closest at a distance of "
			<< closestDistance << ".\n";
		cout << "Asteroid is too large too mine.\n" << "Would you like to blast it?\n";
		cout << "1. Yes\n" << "2. No\n";
		cin >> selection;

		if (selection == 1) {
			myAsteroids[closestIndex].setCollected(1);
			cout << "You just blasted the fuck outa that thing!!!\n";
		}
		else if (selection = 2) {
			myAsteroids[closestIndex].setCollected(1);
			cout << "You pansy!\n";
		}
		else {
			myAsteroids[closestIndex].setCollected(1);
			cout << "not an option. asteroid skipped!!\n";
		}
		system("pause");
		system("CLS");
	}
	else {
		cout << "Asteroid " << closestIndex + 1 << " is the closest at a distance of "
			<< closestDistance << ".\n";
		cout << "It weighs " << myAsteroids[closestIndex].getWeight() << ".\n";
		cout << "Moving to coordinates [" << asteroidX << ','
			<< asteroidY << "]\n";

		outfile << setw(8) << ' ';
		outfile << setw(3) << left << myAsteroids[closestIndex].getIndex();
		outfile << setw(9) << ' ';
		outfile << setw(5) << right << myAsteroids[closestIndex].getXCoord() << ','
			<< myAsteroids[closestIndex].getYCoord();
		outfile << setw(6) << ' ';
		outfile << setw(4) << right << myAsteroids[closestIndex].getWeight();
		outfile << setw(25) << right << closestDistance;
		outfile << endl;

		system("pause");

		moveShip(asteroidX, asteroidY, closestDistance);
		collectAsteroid(myAsteroids, closestIndex);
	}
}

void Ship::collectAsteroid(vector<Asteroid>& myAsteroids, int i) {
	myAsteroids[i].setCollected(1);
	totWeight += myAsteroids[i].getWeight();
}

void Ship::moveShip(double x, double y, double d) {
	shipXCoord = x;
	shipYCoord = y;
	totDistance += d;
}