/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_craft inherets from space_object and is used to control movement
and the functionality of both ship and probe
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "asteroid.h"
#include "space_craft.h"

// Default Constructor
SpaceCraft::SpaceCraft() {
	totDistance = 0;
	shipHealth = 100;
}

// Overloaded Constructor
SpaceCraft::SpaceCraft(double d, double h) {
	totDistance = d;
	shipHealth = h;
}

//Copy Constructor
SpaceCraft::SpaceCraft(const SpaceCraft& SC) {
	totDistance = SC.totDistance;
	shipHealth = SC.shipHealth;
}

//Destructor
SpaceCraft::~SpaceCraft() {

}

// @param int, int, double - xCoord, yCoord, distance
void SpaceCraft::moveLoc(int x, int y, double d) {
	setXCoord(x);
	setYCoord(y);
	totDistance += d;
}

// @param vector - Asteroids
//			Finds closest asteroid
void SpaceCraft::findAsteroid(std::vector<Asteroid>& myAsteroids) {
	unsigned int size = myAsteroids.size();
	int asteroidX;
	int asteroidY;
	int closestIndex = 0;
	int selection = 0;
	double closestDistance = DBL_MAX;


	// loops through entire vector of asteroids
	for (unsigned int i = 0; i < size; i++) {
		double distance = 0;

		// updates coords of asteroid
		asteroidX = myAsteroids[i].getXCoord();
		asteroidY = myAsteroids[i].getYCoord();

		//distance formula using pythagorean theorem
		distance = sqrt(pow((asteroidX - getXCoord()), 2) 
					+ pow((asteroidY - getYCoord()), 2));

		//updates closest asteroid
		if (!myAsteroids[i].isCollected() && distance < closestDistance) {
			closestIndex = i;
			closestDistance = distance;
		}
	}
	//updates asteroid coord with closest
	asteroidX = myAsteroids[closestIndex].getXCoord();
	asteroidY = myAsteroids[closestIndex].getYCoord();

	// makes sure asteroid is "mineable"
	if (myAsteroids[closestIndex].isTooBig())
		//display IO for user
		std::cout << "\nAsteroid " << closestIndex - 1 
			<< " is too large to mine.\n";
	else if (!myAsteroids[closestIndex].isTooBig() 
		&& !myAsteroids[closestIndex].isCollected()) {

		std::cout << "\nAsteroid " << closestIndex + 1 
			<< " is the closest at a distance of "
			<< closestDistance << " and weighs " 
			<< myAsteroids[closestIndex].getWeight() << ".\n";
		std::cout << "Moving to coordinates [" << asteroidX << ','
			<< asteroidY << "]\n\n";

		system("pause");

		// move location and collect
		moveLoc(asteroidX, asteroidY, closestDistance);
		collect(myAsteroids, closestIndex);
	}
}

// Collects asteroids and adds weight to total for data upkeep
void SpaceCraft::collect(std::vector<Asteroid>& myAsteroids, int i) {
	myAsteroids[i].setCollected(true);
}

// updates num of asteroids collected
void SpaceCraft::setNumCollect(int c) {
	numCollect = c;
}

//@return double
// gets totDistance for both probe and ship
double SpaceCraft::getTotDistance() {
	return totDistance;
}

// @return double
// gets totDistance for both probe and ship
double SpaceCraft::getShipHealth() {
	return shipHealth;
}

//@return unsigned int
// how many asteroids to collect or visit
unsigned int SpaceCraft::getNumCollect() {
	return numCollect;
}