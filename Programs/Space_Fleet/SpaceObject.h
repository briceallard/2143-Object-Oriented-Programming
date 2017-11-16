/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
space_object is the parent class for all inherited classes
and will control coordinates of both ship and probe
*/

#pragma once
#include <string>

class SpaceObject {
public:
	// Pure Virtual toString
	virtual std::string toString() = 0;

	//Accessor Functions
	int getX() const;
	int getY() const;
	std::string getName();

	//Mutator Functions
	void setX(int);
	void setY(int);

protected:
	// Member Variables
	int xCoord;
	int yCoord;
	std::string name;
};