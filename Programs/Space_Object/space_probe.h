/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_probe controls the probe movement and collection of data
*/

#pragma once
#include <vector>
#include "space_craft.h"

class SpaceProbe : public SpaceCraft {
public:
	// Default Constructor
	SpaceProbe();

	// Overloaded Constructor
	SpaceProbe(int, int);

	// Copy Constructor
	SpaceProbe(const SpaceProbe&);

	// Destructor
	~SpaceProbe();

	// Accessor Functions
	int getPrec();
	// getPrec
	// @return int - number of precious asteroids found

	// Mutator Functions
	virtual void findAsteroid(std::vector<Asteroid>&);
	virtual void collect(std::vector<Asteroid>&, int);

private:
	// member variables
	int precious;
};