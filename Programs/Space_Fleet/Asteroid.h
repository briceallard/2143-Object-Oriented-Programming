/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
Asteroid manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#pragma once
#include "SpaceObject.h"

class Asteroid : public SpaceObject {
public:
	// Constructors
	Asteroid();
	Asteroid(int, int, double, bool);
	Asteroid(const Asteroid&);
	// Destructors
	~Asteroid();

	//Accessor Functions

	// getPrec
	// @erturn bool - T/F is asteroid Precious Metal
	bool getPrecious() const;
	// getVisited
	// @param bool - T/F has asteroid been visited
	bool getVisited() const;
	// getCollected
	// @param bool - T/F has asteroid been collected
	bool getCollected() const;
	// getTooLarge
	// @param bool - T/F is asteroid too large
	bool getTooLarge() const;
	// getSize
	// @param double - size of asteroid
	double getSize() const;
	// getMaxSize
	// @param double - maximum Size allowed to mine
	static double getMaxSize();
	// toString
	// @param string - Asteroid data in string format
	std::string toString();

	//Operator Overload
	void operator = (const Asteroid&);

	//Mutator Functions
	void setCollected(bool);
	void setVisited(bool);
	static void setMaxSize(double);

private:
	// member Variables
	bool precious, visited, collected;
	double size;
	static double maxSize;
};