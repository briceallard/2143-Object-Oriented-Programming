/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_probe controls the probe movement and collection of data
*/

#include "SpaceProbe.h"
#include <sstream>
#include <iostream>
#include <iomanip>

// Default Constructor
SpaceProbe::SpaceProbe() {
	name = "SpaceProbe";
}

// Overloaded Constructor
SpaceProbe::SpaceProbe(int x, int y) : SpaceCraft(x, y) {
	name = "SpaceProbe";
}

// Copy Constructor
SpaceProbe::SpaceProbe(const SpaceProbe& SP) : SpaceCraft(SP) {
	name = SP.name;
}

// Destructor
SpaceProbe::~SpaceProbe() {

}

// @ param vector - asteroid list
// Finds closest asteroid in the list
void SpaceProbe::getClosest(std::vector<Asteroid>& myAst) {
	unsigned int size = myAst.size();
	int asteroidX;
	int asteroidY;
	int closestIndex = 0;
	int selection = 0;
	double closestDistance = DBL_MAX;

	// loops through entire vector of asteroids
	for (unsigned int i = 0; i < size; i++) {
		double distance = 0;

		// updates coords of asteroid
		asteroidX = myAst[i].getX();
		asteroidY = myAst[i].getY();

		//distance formula using pythagorean theorem
		distance = sqrt(pow((asteroidX - getX()), 2)
			+ pow((asteroidY - getY()), 2));

		//updates closest asteroid
		if (!myAst[i].getCollected() && distance < closestDistance
			&& !myAst[i].getVisited()) {
			closestIndex = i;
			closestDistance = distance;
		}
	}
	//updates asteroid coord with closest
	asteroidX = myAst[closestIndex].getX();
	asteroidY = myAst[closestIndex].getY();

	// move location and collect
	setLoc(asteroidX, asteroidY, closestDistance);
	collect(closestIndex, myAst);
}

// @param vector - Asteroid list
// Sets asteroid[i] to visited and adds to PrecList
void SpaceProbe::collect(int i, std::vector<Asteroid>& myAst) {
	myAst[i].setVisited(true);

	if (myAst[i].getPrecious())
		precList.push_back(myAst[i]);
	totVisited++;
}

// @return string - Probe data in string format
std::string SpaceProbe::toString() {
	std::ostringstream s;	// declare string stream
	s << std::setw(20) << "\nCoords: (" << getX()
		<< ',' << getY() << ')';
	s << std::setw(20) << "Collected: (" << getTotVisit() << '/'
		<< getVisit() << ")\n";

	std::string data = s.str();	// copy stream to string
	return data;				// return string
}