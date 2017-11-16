/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_probe controls the probe movement and collection of data
*/

#pragma once
#include "SpaceCraft.h"

class SpaceProbe : public SpaceCraft {
public:
	// Constructors
	SpaceProbe();
	SpaceProbe(int, int);
	SpaceProbe(const SpaceProbe&);
	// Destructor
	~SpaceProbe();

	//Accessor Functions
	virtual void getClosest(std::vector<Asteroid>&);
	// getClosest
	// Inherited class - finds closest asteroid

	//Mutator Functions
	virtual void collect(int, std::vector<Asteroid>&);
	std::string toString();

private:
	// No member variables
};