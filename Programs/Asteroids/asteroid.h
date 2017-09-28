#pragma once

using namespace std;

class Asteroid {
/////////////////////////////////////////////////////
public:
	// Default Constructor
	Asteroid();

	//Overload Constructor
	Asteroid(double, double, double);

	// Destructor
	~Asteroid();

	// Accessor Functions
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

	//Mutator Functions
	void setWeight(double);
	void setXCoord(double);
	void setYCoord(double);
	void setCollected(bool);


/////////////////////////////////////////////////////
private:
	// Member Variables
	double weight;
	double xCoord;
	double yCoord;
	bool collected;
};