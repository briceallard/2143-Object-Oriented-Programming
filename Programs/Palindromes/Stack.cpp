/*
Brice Allard
2143 - Object Oriented Programming
Dr. Catherine Stringfellow
Program 1 - Palindromes
09/05/2017
*/

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

/*
*@FunctionName: Stack
*@Description:
*			Class Constructor
*@Params:
*			int insize - initial stack size
*@Returns:
*			void
*/
Stack::Stack(int insize) {
	size = insize;
	top = -1;
	S = new char[size];
}

/*
*@FunctionName: Push
*@Description:
*			Adds characters into the stack
*@Params:
*			char c - character being added
*@Returns:
*			void
*/
void Stack::push(char c) {
	if (!full()) {
		S[++top] = c;
	}
	else {
		cout << "Stack Overflow!" << endl;
	}
}

/*
*@FunctionName: Pop
*@Description:
*			Returs a character from the top of the stack
*@Params:
*			None
*@Returns:
*			Char
*/
char Stack::pop() {
	if (!empty())
		return S[top--];
	else
		return false;
}

/**
* @FunctionName: printStack
* @Description:
*     Prints stack to stdout for debugging purposes
* @Params:
*    None
* @Returns:
*    void
*/
void Stack::printStack() {
	for (int i = top; i >= 0; i--) {
		cout << S[i];
	}
	cout << endl;
}

/**
* @FunctionName: empty
* @Description:
*     Checks to see if stack is empty.
* @Params:
*    None
* @Returns:
*    bool - true if empty / false otherwise
*/
bool Stack::empty() {
	return top == -1;
}

/**
* @FunctionName: full
* @Description:
*     Checks if stack is full
* @Params:
*    None
* @Returns:
*    bool - true if full / false otherwise
*/
bool Stack::full() {
	return top == size - 1;
}

/**
* @FunctionName: Peek
* @Description:
*     Determine that value of the top of the stack
* @Params:
*    None
* @Returns:
*    int - Top of the stack
*/
int Stack::peek() {
	if (!empty())
		return S[top];
	else
		//cout << "Cannot peek!" << endl;
		return NULL;
}