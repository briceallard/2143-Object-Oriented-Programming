/*
Brice Allard
Program 3 - Asteroids
Dr. Stringfellow

Asteroids takes asteroid data from an input file and stores it
into a vector. The user is given the option to mine each asteroid
using a ship in outerspace. We track how many asteroids user has
collected, total weight, and distance traveled.

*UPDATE*
Probe added to determine the material makeup of asteroids and
then adds those that are "precious" to vector for later mining.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include "space_ship.h"
#include"space_probe.h"

using namespace std;

void fillVector(vector<Asteroid>&);
// fillVector ==> gets Asteroid information from infile
// @param vector<Asteroid>& - Asteroids in field

void printVector(vector<Asteroid>&);
// printVector ==> prints information about all asteroids
// @param const vector<Asteroid>& ==> Asteroids in field

void initiateLaunch(SpaceShip&, SpaceProbe&, 
	vector<Asteroid>&);
// initiateLaunch ==> gets user input and establishes ship
//						launch location

void delay(int, unsigned int);
// delay ==> pause with a '.' every second for output

void briefMission(SpaceShip&, SpaceProbe&);
// briefMission ==> Prints out summary of mission

void startMission(SpaceShip&, SpaceProbe&, vector<Asteroid>&);
// mission ==> completes the mining and visiting 
//				for SpaceCrafts

int main() {	
	// Create Objects of SpaceShip and SpaceProbe
	SpaceShip SS;
	SpaceProbe SP;

	//Create vector of asteroids
	vector<Asteroid> myAsteroids;

	// Lets fill that vector with something
	fillVector(myAsteroids);

	// collect user information and begin
	initiateLaunch(SS, SP, myAsteroids);

	// launch space ships and probes
	startMission(SS, SP, myAsteroids);

	// summary and/or mission details
	briefMission(SS, SP);

	//GOODBYE!
	system("pause");
	return 0;
}

//@param vector
// fills the vector with asteroid data from infile
void fillVector(vector<Asteroid>& myAsteroids) {
	int x;
	int y;
	double weight;
	int index = 1;
	char precious;
	bool p = false;

	//open input data to read from
	ifstream infile;
	infile.open("asteroid_data.txt");

	//read in data
	infile >> x >> y >> weight >> precious;

	// is this precious?
	if (precious == 'P')
		p = true;
	else
		p = false;

	// repeat above until end of file
	while (!infile.eof()) {
		Asteroid newAsteroid(x, y, weight, index, p);
		myAsteroids.push_back(newAsteroid);

		infile >> x >> y >> weight >> precious;
		if (precious == 'P')
			p = true;
		else
			p = false;
		index++;
	}
}

// @param vector
// prints vector of objects (primarily for testing)
void printVector(vector<Asteroid>& myAsteroids) {
	unsigned int size = myAsteroids.size();

	// loop through entire vector from beg. to end
	for (unsigned int i = 0; i < size; i++) {
		cout << "Asteroid " << i + 1 << "- \n";
		cout << "X: " << myAsteroids[i].getXCoord() << ' ';
		cout << "Y: " << myAsteroids[i].getYCoord() << ' ';
		cout << "Weight: " << myAsteroids[i].getWeight() << ' ';
		cout << "Prec: " << myAsteroids[i].isPrec() << '\n';
	}
}

// @param SpaceShip, SpaceProbe, vector
// Mostly collects data from user via IO
void initiateLaunch(SpaceShip& SS, SpaceProbe& SP, 
					vector<Asteroid>& myAsteroids) {
	int x = 0;
	int y = 0;
	int userCollects = 0;
	int selection = 0;
	unsigned int maxAsteroids = myAsteroids.size();

	// Welcome to SpaceAsteroid, INC.
	cout << "--- SpaceAsteroid, Inc ---\n\n";
	cout << "Analyzing system data";
	delay(1, 3);
	cout << "Initializing radar";
	delay(1, 3);
	cout << "Booting AI";
	delay(1, 3);
	cout << "\nWelcome, Captain!\n";
	cout << "Where would you like to mine today?\n";
	cout << "1. Default [0,0]\n";
	cout << "2. Specify Location\n";
	cout << "Input (1-2): ";
	cin >> selection;
	cout << '\n';

	//default coordinates (0,0)
	if (selection == 1) {
		SS.setXCoord(x);	// sets ship x
		SS.setYCoord(y);	// sets ship y

		cout << "Default coordinates entered into navigation.\n\n";
		system("pause");
	}
	//user enters coordinates
	else if (selection == 2) {
		cout << "Enter coordinates for your ship ...\n";
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		cout << '\n';

		SS.setXCoord(x);
		SS.setYCoord(y);

		cout << '[' << SS.getXCoord() << ',' << SS.getYCoord()
			<< "] coordinates entered into navigation.\n\n";
		system("pause");
	}
	// User goofed up. Default coords used (0,0)
	else {
		SS.setXCoord(x);
		SS.setYCoord(y);

		cout << "Invalid selection!\n";
		cout << "\nDefault coordinates entered into navigation.\n";
		system("pause");
	}

	system("CLS");

	// Get probe launch data
	cout << "\nLaunch probe to same coordinates?\n";
	cout << "1. [" << SS.getXCoord() << ',' << SS.getYCoord()
		<< "]\n";
	cout << "2. Specify Location\n";
	cout << "Input (1-2): ";
	cin >> selection;
	cout << '\n';

	// probe to same coords as ship? Why not!
	if (selection == 1) {
		SP.setXCoord(SS.getXCoord());	// sets probe x to ship x
		SP.setYCoord(SS.getYCoord());	//  ''	  ''  y ''  ''  y

		cout << "Default coordinates entered into navigation.\n";
		cout << "\nPress ENTER to make hyper-jump and begin "
			<< "expidition.\n\n";
		system("pause");
	}
	// user coords for probe launch
	else if (selection == 2) {
		cout << "Enter coordinates for your probe ...\n";
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		cout << '\n';

		SP.setXCoord(x);
		SP.setYCoord(y);

		cout << '[' << SP.getXCoord() << ',' << SP.getYCoord()
			<< "] coordinates entered into navigation.\n";
		cout << "\nPress ENTER to make hyper-jump and begin "
			<< "expidition.\n\n";
		system("pause");
	}
	// user goofed again ... come on!
	else {
		// default coords (ships coords entered previously)
		SP.setXCoord(SS.getXCoord());
		SP.setYCoord(SS.getYCoord());

		cout << "Invalid selection!\n";
		cout << "Default coordinates entered into navigation.\n";
		cout << "\nPress ENTER to make hyper-jump and begin "
			<< "expidition.\n\n";
		system("pause");
	}

	// we have lift off
	cout << "\nLaunch Initiated";
	delay(1, 3);
	cout << "Entering hyper-space";
	delay(1, 3);
	cout << "Scanning environment";
	delay(1, 3);
	cout << "\nRadar has located " << maxAsteroids
		<< " asteroids in your current solar system.\n";
	cout << "How many would you like to mine today Captain?\n";
	cout << "Input (1-" << maxAsteroids << "): ";
	cin >> userCollects;
	SS.setNumCollect(userCollects);
	cout << "\nHow many would you like probe to visit?\n";
	cout << "Input (1-" << maxAsteroids << "): ";
	cin >> userCollects;
	SP.setNumCollect(userCollects);
	
	system("CLS");

	// mission details
	cout << "Captain, here is the mission objective ...\n";
	cout << " - Ship will collect " << SS.getNumCollect()
		<< " asteroids and has launched to [" << SS.getXCoord()
		<< ',' << SS.getYCoord() << "].\n";
	cout << " - Probe will visit " << SP.getNumCollect()
		<< " asteroids and has launched to [" << SP.getXCoord()
		<< ',' << SP.getYCoord() << "].\n";

	cout << "\nPress ENTER to confirm.\n\n";
	system("pause");
}

// simple delay feature for boot animation :}
void delay(int time, unsigned int loop) {
	int timer = time * 1000;

	for (unsigned int i = 0; i < loop; i++) {
		cout.flush();
		Sleep(timer);
		cout << ". ";
	}
	cout << "DONE!" << endl;
	cout.flush();
}

// @param SpaceShip, SpaceProbe
// IO data for mission details once complete
void briefMission(SpaceShip& SS, SpaceProbe& SP) {
	system("CLS");
	int selection = 0;
	cout << "Captain, our mission is complete.\n";
	cout << "Would you like to display the mission briefing?\n";
	cout << "1. Yes\n";
	cout << "2. No [EXIT]\n";
	cout << "(1-2): ";
	cin >> selection;

	// Lets see dem' stats .... 
	if (selection == 1) {

		// Such beautiful craftsmanship on this table data
		cout << fixed << setprecision(2);
		cout << "\t\tShip Collection Data\n";
		cout << "==================================================\n";
		cout << "  # Collected  \t Total Weight     Total Distance  \n";
		cout << "==================================================\n";
		cout << setw(13) << SS.getNumCollect()
			<< setw(16) << SS.getTotWeight()
			<< setw(19) << SS.getTotDistance()
			<< "\n\n";

		cout << "\t\tProbe Collection Data\n";
		cout << "==================================================\n";
		cout << "  # Visited  \t Total Precious     Total Distance  \n";
		cout << "==================================================\n";
		cout << setw(11) << SP.getNumCollect()
			<< setw(18) << SP.getPrec()
			<< setw(19) << SP.getTotDistance()
			<< "\n\n";

	}
}

// @param SpaceShip, SpaceProbe, vector
// Initiates mission and begins the locating of asteroids
// to collect for both SpaceShip and SpaceProbe
void startMission(SpaceShip& SS, SpaceProbe& SP, 
	vector<Asteroid>& myAsteroids) {

	cout << "Ship has begun mission ... \n\n";

	for (unsigned int i = 0; i < SS.getNumCollect(); i++)
		SS.findAsteroid(myAsteroids);

	cout << "Probe has begun mission ... \n\n";

	for (unsigned int i = 0; i < SP.getNumCollect(); i++)
		SP.findAsteroid(myAsteroids);
}