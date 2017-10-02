#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <vector>
#include "asteroid.h"
#include "ship.h"

using namespace std;

Asteroid::Asteroid() {
	weight = 0;
	xCoord = 0;
	yCoord = 0;
	index = 0;
	collected = false;
}

Asteroid::Asteroid(double x, double y, double w, int i) {
	xCoord = x;
	yCoord = y;
	weight = w;
	index = i;
	collected = false;
}

Asteroid::~Asteroid() {

}

int Asteroid::getIndex() {
	return index++;
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

bool Asteroid::isTooBig() {
	maxWeight = 10;

	if (maxWeight < getWeight())
		return true;
	return false;
}

void Asteroid::setIndex(int i) {
	index = i;
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