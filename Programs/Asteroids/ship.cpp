#include "ship.h"

using namespace std;

Ship::Ship() {
	totWeight = 0;
	totDistance = 0;
	shipXCoord = 0;
	shipYCoord = 0;
	shipHealth = 100;
}

Ship::Ship(double x, double y) {
	totWeight = 0;
	totDistance = 0;
	shipXCoord = x;
	shipYCoord = y;
	shipHealth = 100;
}

Ship::~Ship() {

}

double Ship::getCollectedWeight() {
	return totWeight;
}

double Ship::getTotalDistance() {
	return totDistance;
}

double Ship::getShipHealth() {
	return shipHealth;
}

double Ship::getXCoord() {
	return shipXCoord;
}

double Ship::getYCoord() {
	return shipYCoord;
}

void Ship::setXCoord(double x) {
	shipXCoord = x;
}

void Ship::setYCoord(double y) {
	shipYCoord = y;
}

void Ship::findAsteroid() {

}

void Ship::collectAsteroid() {

}