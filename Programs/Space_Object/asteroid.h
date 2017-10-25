/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

Asteroid manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#include "space_object.h"
#pragma once

class Asteroid :public SpaceObject {
public:
	// Default Constructor
	Asteroid();

	// Overloaded Constructor
	Asteroid(double, double, double, int, bool);

	//Copy Constructor
	Asteroid(const Asteroid&);

	// Destructor
	~Asteroid();

	// Accessor Functions
	int getIndex();
	// getIndex
	// @param int - index of asteroid in vector

	double getWeight();
	// getWeight
	// @param double - weight of asteroid

	bool isPrec();
	// getPrec
	// @erturn bool - T/F is asteroid Precious Metal

	bool isCollected();
	// isCollected
	// @param bool - T/F has asteroid been collected

	bool isVisited();
	// isVisited
	// @param bool - T/F has asteroid been visited

	bool isTooBig();
	// tooBig
	// @param bool - T/F is asteroid too large

	// Mutator Functions
	void setIndex(int);
	void setWeight(double);
	void setCollected(bool);
	void setVisited(bool);
	void setPrec(char);

private:
	// Member Variables
	double weight;
	double maxWeight;
	bool prec;
	int index;
	bool collected;
	bool visited;
};