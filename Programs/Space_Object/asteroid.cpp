/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

Asteroid.cpp manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#include "asteroid.h"

// Default Constructor
Asteroid::Asteroid() {
	xCoord = 0;
	yCoord = 0;
	weight = 0;
	index = 0;
	prec = false;
	collected = false;
	visited = false;
}

// Overloaded Constructor
Asteroid::Asteroid(double x, double y, double w, int i, bool p) {
	xCoord = x;
	yCoord = y;
	weight = w;
	index = i;
	prec = p;
	collected = false;
	visited = false;
}

//Copy Constructor
Asteroid::Asteroid(const Asteroid& As) {
	xCoord = As.xCoord;
	yCoord = As.yCoord;
	weight = As.weight;
	index = As.index;
	prec = As.prec;
	collected = false;
	visited = false;
}

//Destructor
Asteroid::~Asteroid() {

}

//@return int - index of asteroid vector + 1
//			for std::out in Source.cpp
int Asteroid::getIndex() {
	return index++;
}

//@return double - returns weight of asteroid
double Asteroid::getWeight() {
	return weight;
}

// @return bool - T/F is precious metal
bool Asteroid::isPrec() {
	return prec;
}

// @return bool - T/F is collected
bool Asteroid::isCollected() {
	return collected;
}

// @return bool - T/F is visited
bool Asteroid::isVisited() {
	return visited;
}

// @return bool - T/F is too big
//				sets max weight here
bool Asteroid::isTooBig() {
	maxWeight = 15;

	if (maxWeight < getWeight()) { 
		return true; }
	return false;
}

// @param int - index passed in
void Asteroid::setIndex(int i) {
	index = i;
}

// @param double - weight passed in
void Asteroid::setWeight(double w) {
	weight = w;
}

// @param bool - collected passed in
void Asteroid::setCollected(bool c) {
	collected = c;
}

// @param bool - visited passed in
void Asteroid::setVisited(bool v) {
	visited = v;
}

// @param char - precious passed in
void Asteroid::setPrec(char p) {
	prec = p;
}