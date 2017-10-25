/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

space_object is the parent class for all inherited classes
and will control coordinates of both ship and probe
*/

#include "space_object.h"

// @param int - x coord of object
int SpaceObject::getXCoord() {
	return xCoord;
}

// @param int - y coord of object
int SpaceObject::getYCoord() {
	return yCoord;
}

void SpaceObject::setXCoord(int x) {
	xCoord = x;
}

void SpaceObject::setYCoord(int y) {
	yCoord = y;
}