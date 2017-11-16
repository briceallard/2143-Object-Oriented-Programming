/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
space_object is the parent class for all inherited classes
and will control coordinates of both ship and probe
*/

#include "SpaceObject.h"

// @param int - x coord of object
void SpaceObject::setX(int x) {
	xCoord = x;
}

// @param int - y coord of object
void SpaceObject::setY(int y) {
	yCoord = y;
}

// @return int - xCoord
int SpaceObject::getX() const {
	return xCoord;
}

// @return int - yCoord
int SpaceObject::getY() const {
	return yCoord;
}

// @return string - name
std::string SpaceObject::getName() {
	return name;
}