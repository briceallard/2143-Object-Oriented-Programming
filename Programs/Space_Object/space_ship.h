/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

Asteroid.cpp manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#pragma once
#include <vector>
#include "space_craft.h"

class SpaceShip :public SpaceCraft {
public:
	// Default Constructor
	SpaceShip();

	// Overloaded Constructor
	SpaceShip(int, int);

	// Copy Constructor
	SpaceShip(const SpaceShip&);

	// Destructor
	~SpaceShip();

	// Accessor Functions
	double getTotWeight();
	// getTotWeight
	// @return double - total weight collected

	// Mutator Functions
	virtual void collect(std::vector<Asteroid>&, int);
	
protected:
	double totWeight;
};