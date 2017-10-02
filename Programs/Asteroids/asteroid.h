#include <math.h>
#include <vector>
#pragma once

using namespace std;

class Asteroid {
	/////////////////////////////////////////////////////
public:
	// Default Constructor
	Asteroid();

	//Overload Constructor
	Asteroid(double, double, double, int);

	// Destructor
	~Asteroid();

	// Accessor Functions
	int getIndex();
	// getIndex
	// @param int - index of asteroid in vector
	double getWeight();
	// getWeight
	// @return double - weight of asteroid
	
	double getXCoord();
	// getXCoord
	// @return double - X coordinate for asteroid location
	double getYCoord();
	// getXCoord
	// @return double - Y coordinate for asteroid location
	bool isCollected();
	// isCollected
	// @return bool - TRUE/FALSE has asteroid been collected
	bool isTooBig();

	//Mutator Functions
	void setIndex(int);
	void setWeight(double);
	void setXCoord(double);
	void setYCoord(double);
	void setCollected(bool);


	/////////////////////////////////////////////////////
private:
	// Member Variables
	double maxWeight;
	double weight;
	double xCoord;
	double yCoord;
	int index;
	bool collected;
};