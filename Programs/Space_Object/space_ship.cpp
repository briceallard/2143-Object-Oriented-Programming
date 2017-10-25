/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

Asteroid.cpp manages vector data of all asteroids in field,
as well as manages asteroid data for user
*/

#include "space_ship.h"

SpaceShip::SpaceShip() {
	totWeight = 0;
}

SpaceShip::SpaceShip(int x, int y) {
	totWeight = 0;
}

SpaceShip::SpaceShip(const SpaceShip & SC) {
	totWeight = SC.totWeight;
}

SpaceShip::~SpaceShip() {

}

double SpaceShip::getTotWeight() {
	return totWeight;
}

void SpaceShip::collect(std::vector<Asteroid>& myAsteroids, int i) {
	myAsteroids[i].setCollected(1);
	totWeight += myAsteroids[i].getWeight();
}