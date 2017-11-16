/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
SpaceShip.cpp is inheriting from SpaceCraft and will manage
the ships that collect each asteroid up to a certain weight.
*/

#include "SpaceShip.h"
#include <sstream>
#include <iomanip>
#include <iostream>

// Default Constructor
SpaceShip::SpaceShip() {
	name = "SpaceShip";
	totWeight = 0;
}

// Overloaded Constructor
SpaceShip::SpaceShip(int x, int y) : SpaceCraft(x, y) {
	name = "SpaceShip";
	totWeight = 0;
}

// Copy Constructor
SpaceShip::SpaceShip(const SpaceShip& SS) : SpaceCraft(SS) {
	name = SS.name;
	totWeight = SS.totWeight;
}

// Desctructor
SpaceShip::~SpaceShip() {

}

// @return double - total weight collected
double SpaceShip::getTotWeight() const {
	return totWeight;
}

// @return - nearest asteroid to current loc
void SpaceShip::getClosest() {
	unsigned int size = precList.size();
	int asteroidX;
	int asteroidY;
	int closestIndex = 0;
	int selection = 0;
	double closestDistance = DBL_MAX;


	// loops through entire vector of asteroids
	for (unsigned int i = 0; i < size; i++) {
		double distance = 0;

		// updates coords of asteroid
		asteroidX = precList[i].getX();
		asteroidY = precList[i].getY();

		//distance formula using pythagorean theorem
		distance = sqrt(pow((asteroidX - getX()), 2)
			+ pow((asteroidY - getY()), 2));

		//updates closest asteroid
		if (!precList[i].getCollected() && distance < closestDistance) {
			closestIndex = i;
			closestDistance = distance;
		}
	}
	//updates asteroid coord with closest
	asteroidX = precList[closestIndex].getX();
	asteroidY = precList[closestIndex].getY();

	// makes sure asteroid is "mineable"
	if (precList[closestIndex].getTooLarge())
		precList[closestIndex].setCollected(true);
	else if (!precList[closestIndex].getTooLarge()
		&& !precList[closestIndex].getCollected()) {
		// move location and collect
		setLoc(asteroidX, asteroidY, closestDistance);
		collect(closestIndex);
	}
}

// @param int - index of asteroid to collect
void SpaceShip::collect(int i) {
	precList[i].setCollected(true);
	totWeight += precList[i].getSize();
	totCollected++;
}

// @return string - Ship data in string format
std::string SpaceShip::toString() {
	std::ostringstream s;	// declare string stream
	s << std::setw(20) << "\nCoords: (" << getX()
		<< ',' << getY() << ')';
	s << std::setw(20) <<"Collected: (" << getTotCollect() << '/'
		<< getCollect() << ")";
	s << std::setw(20) << "Size: " << std::fixed << std::setprecision(2)
		<< totWeight << " kT\n";

	std::string data = s.str();	// copy stream to string
	return data;				// return string
}