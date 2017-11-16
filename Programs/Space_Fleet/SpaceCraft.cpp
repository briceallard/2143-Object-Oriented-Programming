/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
space_craft inherets from space_object and is used to control movement
and the functionality of both ship and probe
*/

#include "SpaceCraft.h"
#include <sstream>
#include <iomanip>
#include <iostream>

// Initialize static varaibles
int SpaceCraft::toVisit = 0;
int SpaceCraft::totVisited = 0;
int SpaceCraft::toCollect = 0;
int SpaceCraft::totCollected = 0;
std::vector<Asteroid> SpaceCraft::precList;

// Default Constructor 
SpaceCraft::SpaceCraft() {
	name = "SpaceCraft";
	xCoord = 0;
	yCoord = 0;
	totVisited = 0;
	totDistance = 0;
}

// Overloaded Cosntructor
SpaceCraft::SpaceCraft(int x, int y) {
	name = "SpaceCraft";
	xCoord = x;
	yCoord = y;
	totVisited = 0;
	totDistance = 0;
}

// Copy Constructor
SpaceCraft::SpaceCraft(const SpaceCraft& SC) {
	name = SC.name;
	xCoord = SC.xCoord;
	yCoord = SC.yCoord;
	totVisited = SC.totVisited;
	totDistance = SC.totDistance;
}

// Destructor
SpaceCraft::~SpaceCraft() {

}

// return vector - precious asteroids list
std::vector<Asteroid> SpaceCraft::getPrecList() const {
	return precList;
}

// return double - total distance traveled
double SpaceCraft::getTotDistance() const {
	return totDistance;
}

// return int - total number to visit
int SpaceCraft::getVisit() const {
	return toVisit;
}

// return int - total number visited
int SpaceCraft::getTotVisit() const {
	return totVisited;
}

// return int - total number to collect
int SpaceCraft::getCollect() const {
	return toCollect;
}

// return int - total number collected
int SpaceCraft::getTotCollect() const {
	return totCollected;
}

// @param vector - Asteroids
//			Finds closest asteroid
void SpaceCraft::getClosest(std::vector<Asteroid>& myAst) {
	unsigned int size = myAst.size();
	double maxS = Asteroid::getMaxSize();
	int asteroidX;
	int asteroidY;
	int closestIndex = 0;
	int selection = 0;
	double closestDistance = DBL_MAX;


	// loops through entire vector of asteroids
	for (unsigned int i = 0; i < size; i++) {
		double distance = 0;

		// updates coords of asteroid
		asteroidX = myAst[i].getX();
		asteroidY = myAst[i].getY();

		//distance formula using pythagorean theorem
		distance = sqrt(pow((asteroidX - getX()), 2)
			+ pow((asteroidY - getY()), 2));

		//updates closest asteroid
		if (!myAst[i].getCollected() && distance < closestDistance) {
			closestIndex = i;
			closestDistance = distance;
		}
	}
}

// Display collection data in string format
std::string SpaceCraft::getList() {
	unsigned int size = precList.size();
	
	std::ostringstream s;	// declare string stream
	s << std::setw(10) << "Asteroid"
		<< std::setw(15) << "Location"
		<< std::setw(15) << "Weight"
		<< std::setw(15) << "Precious\n"
		<< std::string(55, '-') << '\n';

	// Loop through each precious asteroid in list
	for (unsigned int i = 0; i < size; i++) {
		s << std::string(5, ' ') << i
			<< std::string(12, ' ')	<< '(' 
			<< precList[i].getX() << ','
			<< precList[i].getY() << ')'
			<< std::string(10, ' ') << std::fixed 
			<< std::setprecision(2) << precList[i].getSize() 
			<< std::string(10, ' ') << std::setprecision(0)
			<< precList[i].getPrecious()
			<< '\n';
	}
	std::string data = s.str();	// set stream to string
	return data;				// return string
}

// Display collection data in string format
std::string SpaceCraft::toString() {
	std::ostringstream s;
	s << "Asteroids Visited: (" << getVisit() + '/'
		<< getTotVisit() << ")\n"
		<< "Asteroids Collected: (" << getCollect() + '/'
		<< getTotCollect() + ")\n\n";

	std::string data = s.str();
	return data;
}

// @param int, vector - setCollected once mined
void SpaceCraft::collect(int i, std::vector<Asteroid>& myAst) {
	myAst[i].setCollected(true);
	totVisited++;
}

// @param int - set number to visit
void SpaceCraft::setToVisit(int n) {
	toVisit = n;
}

// @param int - set number to Collect
void SpaceCraft::setToCollect(int n) {
	toCollect = n;
}

// @param int, int, double - xCoord, yCoord, distance
void SpaceCraft::setLoc(int x, int y, double d) {
	setX(x);
	setY(y);
	totDistance += d;		// Add distance traveled
}