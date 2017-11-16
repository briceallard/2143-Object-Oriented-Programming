/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
SpaceShip.h is inheriting from SpaceCraft and will manage
the ships that collect each asteroid up to a certain weight.
*/

#pragma once
#include "SpaceCraft.h"

class SpaceShip : public SpaceCraft {
public:
	//Constructors
	SpaceShip();
	SpaceShip(int, int);
	SpaceShip(const SpaceShip&);
	//Destructor
	~SpaceShip();

	//Accessor Functions
	double getTotWeight() const;
	// getTotWeight
	// @return double - total weight collected
	virtual void getClosest();
	// getClosest
	// Inherited - Finds closest precious ast

	//Mutator Functions
	virtual void collect(int);
	std::string toString();

private:
	// Member Variables
	double totWeight;
};