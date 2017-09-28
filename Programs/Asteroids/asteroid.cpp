#include "asteroid.h"

using namespace std;

Asteroid::Asteroid() {
	weight = 0;
	xCoord = 0;
	yCoord = 0;
	collected = 0;
}

Asteroid::Asteroid(double x, double y, double w) {
	xCoord = x;
	yCoord = y;
	weight = w;
}

Asteroid::~Asteroid() {

}



double Asteroid::getWeight() {
	return weight;
}

double Asteroid::getXCoord() {
	return xCoord;
}

double Asteroid::getYCoord() {
	return yCoord;
}

bool Asteroid::isCollected() {
	return collected;
}

void Asteroid::setWeight(double w) {
	weight = w;
}

void Asteroid::setXCoord(double x) {
	xCoord = x;
}

void Asteroid::setYCoord(double y) {
	yCoord = y;
}

void Asteroid::setCollected(bool c) {
	collected = c;
}