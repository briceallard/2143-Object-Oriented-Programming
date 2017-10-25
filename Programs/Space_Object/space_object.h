/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_object is the parent class for all inherited classes
and will control coordinates of both ship and probe
*/

#pragma once

class SpaceObject {

public:
	// Accessor Functions
	int getXCoord();
	// getXCoord
	// @return double - X Coordinate of a particular object

	int getYCoord();
	// getYCoord
	// @return double - Y Coordinate of a particular object

	// Mutator Functions
	void setXCoord(int);	// sets x coord
	void setYCoord(int);	// sets y coord

protected:
	// Member variables
	int xCoord;
	int yCoord;
};