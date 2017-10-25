/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_craft inherets from space_object and is used to control movement
and the functionality of both ship and probe
*/

#pragma once
#include <vector>
#include "asteroid.h"
#include "space_object.h"

class SpaceCraft :public SpaceObject {
public:
	// Default Constructor
	SpaceCraft();

	// Overloaded Cosntructor
	SpaceCraft(double, double);

	// Copy Constructor
	SpaceCraft(const SpaceCraft&);
	
	// Destructor
	~SpaceCraft();

	// Accessor Functions
	double getTotDistance();
	// getTotDistance
	// @return double - total distance traveled
	double getShipHealth();
	// getShipHealth
	// @return double - current ships health
	unsigned int getNumCollect();
	// getNumCollect
	// @return int - total number to collect

	// Mutator Functions
	void moveLoc(int, int, double);
	virtual void findAsteroid(std::vector<Asteroid>&);
	virtual void collect(std::vector<Asteroid>&, int);
	void setNumCollect(int);

protected:
	// Member Variables
	unsigned int numCollect;
	double totDistance;
	double shipHealth;
};