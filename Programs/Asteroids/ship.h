#include <math.h>
#include <vector>
#include "asteroid.h"
#pragma once

using namespace std;

class Ship {
/////////////////////////////////////////////////////
public:
	// Default constructor
	Ship();

	// Overloaded constructor
	Ship(double, double);

	//Destructor
	~Ship();

	// Accessor functions
	double getCollectedWeight();
	// getCollectedWeight
	// @return double - total weight collected
	double getTotalDistance();
	// getTotalDistance
	// @return double - total distance traveled
	double getShipHealth();
	// getShipHealth
	// @return double - Current ships health
	double getXCoord();
	// getXCoord
	// @return double - X coordinate for ship location
	double getYCoord();
	// getXCoord
	// @return double - Y coordinate for ship location

	// Mutator functions
	void setXCoord(double);
	void setYCoord(double);
	void findAsteroid(vector<Asteroid>&);
	void collectAsteroid(vector<Asteroid>&, int);
	void moveShip(double, double, double);
/////////////////////////////////////////////////////
private:
	//Member variables
	double totWeight;
	double totDistance;
	double shipXCoord;
	double shipYCoord;
	double shipHealth;
};