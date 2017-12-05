/*
Brice Allard
Program 5 - Team Queue
Dr. Stringfellow

Team Queue is similiar to a standard queue however it
implements a priority based list that inserts higher priority
items before lower priority. In this case, team 1 > team 2 > team 3.

** Ability to use standard queue implementation is possible by
	changing all L.Insert() to L.Enqueue().
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"

using namespace std;

string initFiles();
// initFiles ==> initiates and opens files based on user input
// @param string - name of the inputfile

void initQueue(List<int>&, string);
// initQueue ==> creates teams and enters them into queue
// @param List<T>& - List (queue) pass by reference where data stored
//			string - infile name to read data from

int main() {
	// Initialize Variables
	List<int> L;
	string infileName;

	//Gather user data for input files
	infileName = initFiles();

	//Begin reading data and organizing queues
	initQueue(L, infileName);

	// All done
	system("pause");
	return 0;
}
