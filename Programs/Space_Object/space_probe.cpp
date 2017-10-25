/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_probe controls the probe movement and collection of data
*/

#include <iostream>
#include "space_probe.h"

// Default Constructor
SpaceProbe::SpaceProbe() {
	precious = 0;
}

// Overloaded Constructor
SpaceProbe::SpaceProbe(int x, int y) {
	precious = 0;
}

//Copy Constructor
SpaceProbe::SpaceProbe(const SpaceProbe& SP) {
	precious = 0;
}

//Destructor
SpaceProbe::~SpaceProbe() {

}

// @return int
// is the asteroid made of precious metal
int SpaceProbe::getPrec() {
	return precious;
}

// @param vector - Asteroids
//			Finds closest asteroid based on new paramenters 
//			for probe
void SpaceProbe::findAsteroid(std::vector<Asteroid>& myAsteroids) {
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
		if (!myAsteroids[i].isCollected() && distance < closestDistance
			&& !myAsteroids[i].isVisited()) {
			closestIndex = i;
			closestDistance = distance;
		}
	}
	//updates asteroid coord with closest
	asteroidX = myAsteroids[closestIndex].getXCoord();
	asteroidY = myAsteroids[closestIndex].getYCoord();

	// move location and collect
	moveLoc(asteroidX, asteroidY, closestDistance);
	collect(myAsteroids, closestIndex);
}

// "Visits" asteroid instead of collects.
void SpaceProbe::collect(std::vector<Asteroid>& myAsteroids, int i) {
	std::vector<Asteroid> precList;	// precious metal asteroid list
	myAsteroids[i].setVisited(true);// sets asteroid to visited

	// determine if asteroid is precious metal
	if (myAsteroids[i].isPrec()) {
		std::cout << "\nAsteroid " << i + 1 
			<< " is made of Precious Metal.\n";
		std::cout << "Adding to database ... \n\n";
		precList.push_back(myAsteroids[i]); // push to vector
		precious++;	// increment precious asteroid count
	}
	else if (!myAsteroids[i].isPrec()) {
		std::cout << "\nAsteroid " << i + 1 
			<< " is NOT made of Precious Metal.\n";
		std::cout << "Finding next Asteroid ... \n\n";
	}

	system("pause");
}