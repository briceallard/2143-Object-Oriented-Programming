/*
Brice Allard
2143 - Object Oriented Programming
Dr. Catherine Stringfellow
Program 1 - Palindromes
09/05/2017
*/

#include <iostream>
#include <string>

using namespace std;

/*
* @FunctionName: Stack
* @Description:
*			Creates a stack in order to store Char types from
			the string input from the user.
*/

class Stack {
private:
	/////////////////////////////////////////////////////////////
	char *S;
	int size;

public:
	/////////////////////////////////////////////////////////////
	int top;

	Stack(int);
	void push(char);
	char pop();
	void printStack();
	bool empty();
	bool full();
	int peek();
};