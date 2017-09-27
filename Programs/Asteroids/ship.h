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
	double getXCoord();
	// getXCoord
	// @return double - X coordinate for ship location
	double getYCoord();
	// getXCoord
	// @return double - Y coordinate for ship location

	// Mutator functions
	void setXCoord(double);
	void setYCoord(double);
	void findAsteroid();
	void collectAsteroid();
/////////////////////////////////////////////////////
private:
	//Member variables
	double totWeight;
	double totDistance;
	double shipXCoord;
	double shipYCoord;
	double shipHealth;
};
