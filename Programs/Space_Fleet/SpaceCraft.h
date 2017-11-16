/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow
space_craft inherets from space_object and is used to control movement
and the functionality of both ship and probe
*/

#pragma once
#include "SpaceObject.h"
#include "Asteroid.h"
#include <vector>

class SpaceCraft : public SpaceObject {
public:
	// Constructors
	SpaceCraft();
	SpaceCraft(int, int);
	SpaceCraft(const SpaceCraft&);
	// Destructor
	~SpaceCraft();

	//Accessor Functions
	std::vector<Asteroid> getPrecList() const;
	// getPrecList
	// @return vector - List of precious asteroids
	double getTotDistance() const;
	// getTotDistance
	// @return double - total distance traveled
	int getVisit() const;
	// getVisit
	// @return int - total number to visit
	int getTotVisit() const;
	// getTotVisit
	// @return int - total number already visited
	int getCollect() const;
	// getCollect
	// @return int - total number to collect
	int getTotCollect() const;
	// getTotCollect
	// @return int - total number already collected
	virtual void getClosest(std::vector<Asteroid>&);
	// getClosest
	// @param vector - finds closest asteroid to collect
	std::string getList();
	// getList
	// @return string - Fleet info in string format
	std::string toString();
	// toString
	// @return string - Fleet info in string format

	//Mutator Function
	virtual void collect(int, std::vector<Asteroid>&);
	static void setToVisit(int);
	static void setToCollect(int);
	void setLoc(int x, int y, double d);

protected:
	// Member Variables
	double totDistance;
	static int toVisit, totVisited, toCollect, totCollected;
	static std::vector<Asteroid> precList;
};