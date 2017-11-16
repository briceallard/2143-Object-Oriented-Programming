/*
Brice Allard
Program 4 - Asteroids
Dr. Stringfellow

Asteroids takes asteroid data from an input file and stores it
into a vector. The user is given the option to mine each asteroid
using a ship in outerspace. We track how many asteroids user has
collected, total weight, and distance traveled.

*UPDATE*
Probe added to determine the material makeup of asteroids and
then adds those that are "precious" to vector for later mining.

**UPDATE 2**
Fleet of "Crafts" added as an array to allow multiple crafts to
scan the asteroid field. Probes visit and find asteroids
populated with precious material for the ships to mine.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "SpaceShip.h"
#include "SpaceProbe.h"

using namespace std;

typedef SpaceCraft* Crafts[50];

void delay(int, unsigned int);
// delay ==> pause with a '.' every second for output

void fillAst(vector<Asteroid>&);
// fillAst ==> gets Asteroid information from infile
// @param vector<Asteroid>& - Asteroids in field

int fillCrafts(Crafts&);
// fillFleet ==> gets Ship information from infile
// @param Crafts& - Ships in fleet

void initLaunch(vector<Asteroid>&, Crafts&, int);
// initLaunch ==> begins launch of Crafts
// @param vector<Asteroid>& - asteroids in field
// @param Crafts& - all spacecrafts in array
// @param int - maximum number of ships

void printReport(const Crafts&, int);
// printReport ==> prints status of Probes and Ships
// @param Crafts& - Crafts in entire fleet

void printFinal(const Crafts&);
// printFinal ==> prints final report of collection data
// @param Crafts& - Crafts in entire fleet

int main() {
	// Initialize all variables
	Crafts crafts;
	vector<Asteroid> myAsteroids;
	SpaceShip SS;
	SpaceProbe SP;

	int maxCrafts = 0;

	// Let's fill the vector with some goodies!
	fillAst(myAsteroids);			// Asteroid data
	maxCrafts = fillCrafts(crafts);	// Ship data

	// Print out the details of our voyage
	printReport(crafts, maxCrafts);

	// Begin voyage
	initLaunch(myAsteroids, crafts, maxCrafts);

	// Print out the updated details
	printReport(crafts, maxCrafts);
	printFinal(crafts);		// final summary report

	// Aww .. Bye bye
	system("pause");
	return 0;
}

// simple delay feature for boot animation :}
void delay(int time, unsigned int loop) {
	int timer = time * 1000;

	for (unsigned int i = 0; i < loop; i++) {
		cout.flush();
		Sleep(timer);
		cout << ". ";
	}
	cout << "DONE!" << endl << endl;
	cout.flush();
}

// @param vector
// Opens and fills vector with data read from infile
//		such as location, weight, precious etc. etc.
void fillAst(vector<Asteroid>& myAst) {
beginning:				// create breakpoint to come back to

	//Declare all variables
	int x, y, selection;
	double weight;
	char prec;
	bool p = false;
	string filename;
	ifstream infile;
	ofstream outfile;

	// Open outfile and truncate any previous saved data
	outfile.open("output.txt", ios::trunc);

	outfile << "Brice Allard - Program 4 - SpaceObjects\n\n";

	// Gather input filename from user or use default
	cout << "Would you like to enter the input file name\n";
	cout << "or use default for the *Asteroid* data?\n";
	cout << "1. Enter File Name\n";
	cout << "2. Use Default\n";
	cout << "(1-2): ";
	cin >> selection;

	// User chose to enter filename
	if (selection == 1) {
		cout << "\nInput File Name: ";
		cin.ignore();
		getline(cin, filename);
		cout << endl;

		infile.open(filename);

		// Verify infile has been opened
		if (infile) {
			cout << '\n' << filename << " Opened Successfully ...\n";
			outfile << '\n' << filename << " Opened Successfully ...\n";
		}
		else {
			cout << "There was an error with the file name entered.\n";
			cout << "Try again ...\n\n";
			outfile << "There was an error with the file name entered.\n";
			outfile << "Try again ...\n\n";
			system("pause");
			system("CLS");
			goto beginning;		// Try again ... 
		}
	}
	// User chose default filename ("asteroid_data.txt")
	else if (selection == 2) {
		cout << "\nDefault Input File Used.\n";

		infile.open("asteroid_data.txt");

		// verify file opened
		if (infile) {
			cout << "\nasteroid_data.txt Opened Successfully ...\n";
			outfile << "\nasteroid_data.txt Opened Successfully ...\n";
		}
		else {
			cout << "\nDefault filename 'asteroid_data.txt' was not located.\n";
			cout << "Please verify it's location and try again ...\n\n";
			outfile << "\nDefault filename 'asteroid_data.txt' was not located.\n";
			outfile << "Please verify it's location and try again ...\n\n";
			system("pause");
			system("CLS");
			goto beginning;		// try again ...
		}
	}
	// User chose wrong ... user should read better
	else {
		cout << "\nInvalid selection.\nTry again ...\n\n";
		system("pause");
		system("CLS");
		goto beginning;
	}

	cout << "\nFilling Vector with Asteroid data";
	delay(1, 3);

	//read in data
	infile >> x >> y >> weight >> prec;

	// is this precious?
	if (prec == 'P')
		p = true;
	else
		p = false;

	// repeat above until end of file
	while (!infile.eof()) {
		// Add asteroid to vector
		Asteroid newAsteroid(x, y, weight, p);
		myAst.push_back(newAsteroid);

		// Get new asteroid data
		infile >> x >> y >> weight >> prec;
		if (prec == 'P')
			p = true;
		else
			p = false;
	}

	system("pause");
	system("CLS");

	// Close all files
	infile.close();
	outfile.close();
}

// @param fleet
// @return - int (fleetSize - number of ships in fleet)
// Opens and fills array with data read from infile
//		such as ship starting locations, type, etc.
int fillCrafts(Crafts& crafts) {
beginning:			// create breakpoint to come back

	// Declare variables
	int selection, craftSize, visit, collect, x, y;
	double maxWeight;
	char craftType;
	string filename;
	ifstream infile;
	ofstream outfile;

	// Open outfile and append to previous data
	outfile.open("output.txt", ios::app);

	cout << "Would you like to enter the input file name\n";
	cout << "or use default for *Space Craft* data? \n";
	cout << "1. Enter File Name\n";
	cout << "2. Use Default\n";
	cout << "(1-2): ";
	cin >> selection;

	//User chose to enter filename
	if (selection == 1) {
		cout << "Input File Name: ";
		cin.ignore();
		getline(cin, filename);
		cout << endl;

		infile.open(filename);

		// verify file opened
		if (infile) {
			cout << filename << " Opened Successfully ...\n\n";
			outfile << filename << " Opened Successfully ...\n\n";
		}
		else {
			cout << "There was an error with the file name entered.\n";
			cout << "Try again ...\n\n";
			outfile << "There was an error with the file name entered.\n";
			outfile << "Try again ...\n\n";
			system("pause");
			system("CLS");
			goto beginning;
		}
	}
	// User chose to use default ("Spacecraft.txt")
	else if (selection == 2) {
		cout << "\nDefault Input File Used.\n\n";

		infile.open("Spacecraft.txt");

		// verify file opened
		if (infile) {
			cout << "Spacecraft.txt Opened Successfully ...\n\n";
			outfile << "Spacecraft.txt Opened Successfully ...\n\n";
		}
		else {
			cout << "\nDefault filename 'Spacecraft.txt' was not located.\n";
			cout << "Please verify it's location and try again ...\n\n";
			outfile << "\nDefault filename 'Spacecraft.txt' was not located.\n";
			outfile << "Please verify it's location and try again ...\n\n";
			system("pause");
			system("CLS");
			goto beginning;			// try again ...
		}
	}
	// User chose wrong ... should read better
	else {
		cout << "Invalid selection.\nTry again ...\n\n";
		system("pause");
		system("CLS");
		goto beginning;
	}

	cout << "Filling Vector with Ship data";
	delay(1, 3);

	//read in data
	infile >> craftSize >> visit >> collect >> maxWeight;
	SpaceCraft::setToVisit(visit);		// tot number to to visit
	SpaceCraft::setToCollect(collect);	// tot number to collect
	Asteroid::setMaxSize(maxWeight);	// max size can collect

	// gather more data
	for (int i = 0; i < craftSize; i++) {
		infile >> craftType >> x >> y;

		// Determine craft type (probe or ship) and set start loc
		if (craftType == 'P')	// is probe
			crafts[i] = new SpaceProbe(x, y);
		else					// must be ship
			crafts[i] = new SpaceShip(x, y);
	}

	system("pause");
	system("CLS");

	// close files
	infile.close();
	outfile.close();

	return craftSize;	// return the Fleet size
}

// @param vector (Asteroids), crafts[], int maxCrafts
// Launches probes, then ships accordingly
void initLaunch(vector<Asteroid>& myAst, Crafts& crafts, int maxCrafts) {
	// declare all variables
	int listSize = myAst.size();
	int visitsCount = 0;
	int collectedCount = 0;
	int x = 0;
	ofstream outfile;

	// open outfile and append data
	outfile.open("output.txt", ios::app);

	// while visits don't exceed max and max asteroid limit
	while (visitsCount < crafts[0]->getVisit() && visitsCount < listSize) {
		// assign address of object to pointer
		// 12 hours to figure this out! 12!!!
		SpaceProbe * SP = dynamic_cast<SpaceProbe *>(crafts[x]);

		// If Probe, then visit closest asteroid
		if (SP != false) {
			SP->getClosest(myAst);
			visitsCount++;
		}

		// if array[x] reaches the max number of crafts
		if (x == maxCrafts - 1)
			x = 0;		// start over
		else
			x++;		// move to next probe
	}
	
	x = 0;		// restart craft count for Ships

	// while collects don't exceed max allowed
	while (collectedCount < crafts[0]->getCollect()) {
		// again, 12 hours! Assign address of object to pointer ... 
		SpaceShip * SS = dynamic_cast<SpaceShip *>(crafts[x]);

		// if Ship, then visit closest
		if (SS != 0) {
			SS->getClosest();
			collectedCount++;
		}

		// if Crafts reaches max
		if (x == maxCrafts - 1)
			x = 0;			// start over
		else
			x++;			// move to next ship
	}

	// Would the user like some print outs of data?
	int selection = 0;
	cout << "\n\nCrafts have completed their jobs. Would you like to print the List?\n";
	cout << "1. Yes\n2. No\n(1-2): ";
	cin >> selection;

	// user selected to print
	if (selection == 1) {
		system("CLS");
		cout << "Asteroids made of Precious Metal:\n\n"
			<< crafts[0]->getList();
		outfile << "Asteroids made of Precious Metal:\n\n"
			<< crafts[0]->getList();
		system("pause");
	}

	// close files
	outfile.close();
}

// @param Crafts& - array of crafts
// IO data for mission details
void printReport(const Crafts& crafts, int maxCrafts) {
	// declare variables
	ofstream outfile;

	// open outfile and append data
	outfile.open("output.txt", ios::app);

	system("CLS");		// keep the screen pretty ;)

	// Loop through craft data
	for (int i = 0; i < maxCrafts; i++) {
		// Yes ... I'll bring it up every time
		SpaceShip * SS = dynamic_cast <SpaceShip *>(crafts[i]);

		// Verify Craft type
		if (SS != false) {
			// Print SpaceShip data
			cout << "\nSpaceCraft Type: " << crafts[i]->getName();
			outfile << "\nSpaceCraft Type: " << crafts[i]->getName();
			cout << SS->toString();
			outfile << SS->toString();
		}
		else {
			// (>.<)
			SpaceProbe * SP = dynamic_cast <SpaceProbe *>(crafts[i]);

			// Verify Craft Type
			if (SP != false) {
				// Print Probe Data
				cout << "\nSpaceCraft Type: " << crafts[i]->getName();
				outfile << "\nSpaceCraft Type: " << crafts[i]->getName();
				cout << SP->toString();
				outfile << SP->toString();
			}
		}
	}

	// close files
	outfile.close();
}

// @param Crafts& - array of crafts
// IO data for completed mission details
void printFinal(const Crafts& crafts) {
	// Declare variables
	ofstream outfile;

	//open outfile and append data
	outfile.open("output.txt", ios::app);

	// print out Collections data
	cout << "\nVisited: (" << crafts[0]->getTotVisit() 
		<< '/' << crafts[0]->getVisit() << ')'
		<< "\nCollected: (" << crafts[0]->getTotCollect()
		<< '/' << crafts[0]->getCollect() << ")\n\n";
	outfile << "\nVisited: (" << crafts[0]->getTotVisit()
		<< '/' << crafts[0]->getVisit() << ')'
		<< "\nCollected: (" << crafts[0]->getTotCollect()
		<< '/' << crafts[0]->getCollect() << ")\n\n";

	//close files
	outfile.close();
}