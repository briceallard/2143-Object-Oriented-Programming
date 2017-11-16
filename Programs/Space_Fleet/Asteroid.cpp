/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
Asteroid manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#include "Asteroid.h"
#include <sstream>
#include <iomanip>

// Initialize static member variable
double Asteroid::maxSize = 0;

// Default Constructor
Asteroid::Asteroid() {
	name = "Asteroid";
	xCoord = 0;
	yCoord = 0;
	size = 0;
	precious = false;
	visited = false;
	collected = false;
}

// Overloaded Constructor
Asteroid::Asteroid(int x, int y, double s, bool p) {
	name = "Asteroid";
	xCoord = x;
	yCoord = y;
	size = s;
	precious = p;
	visited = false;
	collected = false;
}

//Copy Constructor
Asteroid::Asteroid(const Asteroid& Ast) {
	name = Ast.name;
	xCoord = Ast.xCoord;
	yCoord = Ast.yCoord;
	size = Ast.size;
	precious = Ast.precious;
	visited = Ast.visited;
	collected = Ast.collected;
}

// Destructor
Asteroid::~Asteroid() {

}

// @return bool - T/F is asteroid precious?
bool Asteroid::getPrecious() const {
	return precious;
}

// @return bool - T/F Has asteroid been visited?
bool Asteroid::getVisited() const {
	return visited;
}

// @return bool - T/F is asteroid already collected?
bool Asteroid::getCollected() const {
	return collected;
}

// @return bool - T/F is asteroid too large
//					to collect?
bool Asteroid::getTooLarge() const {
	if (size > maxSize)
		return true;
	else
		return false;
}

//@return double - returns size of asteroid
double Asteroid::getSize() const {
	return size;
}

//@return double - returns max size to collect
double Asteroid::getMaxSize() {
	return maxSize;
}

// @return string - asteroid data in string format
std::string Asteroid::toString() {
	std::ostringstream s; // create stream string for formatting

	s << std::setw(20) << "(" << std::to_string(xCoord)
		<< ',' << std::to_string(yCoord) << ')'
		<< std::fixed << std::setprecision(2) << std::setw(10)
		<< size << std::setw(10) << precious;

	std::string data = s.str();		// Move to string for return
	return data;					// return string
}

// Overload the '=' Operator to allow deep copy of Asteroid arrays
void Asteroid::operator = (const Asteroid& Ast) {
	name = Ast.name;
	xCoord = Ast.xCoord;
	yCoord = Ast.yCoord;
	size = Ast.size;
	precious = Ast.precious;
	visited = Ast.visited;
	collected = Ast.collected;
}

// set collected to T/F
void Asteroid::setCollected(bool c) {
	collected = c;
}

// set visited to T/F
void Asteroid::setVisited(bool v) {
	visited = v;
}

// set maximumsize of asteroid to mine
void Asteroid::setMaxSize(double s) {
	maxSize = s;
}