/*
Brice Allard
2143 - Object Oriented Programming
Dr. Catherine Stringfellow
Program 1 - Palindromes
09/05/2017

@ Description:
		This program determines whether or not a string
		(input from stdin) is balanced in regards to opening
		and closing parantheses.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

using namespace std;

/*
*@ClassName: Palindromes
*@Description:
*			Class
*@Params:
*			Stack *S - Holds parantheses data
			string UI - user input from STDIN
*/
class Palindromes {
private:
/////////////////////////////////////////////////////////////
	Stack *S;
	string UI;

	ifstream infile;
	ofstream outfile;
	
	/*
	*@FunctionName: StackBal
	*@Description:
	*			Determines input string from user and isolates
				the parantheses into the stack.
	*@Params:
	*			string input = UI (input from user STDIN)
	*@Returns:
	*			stack empty (true/false)
	*/

	bool StackBal(string input) {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '(')
				S->push(input[i]);
			else if (input[i] == ')') {
				if (S->empty())
					return false;
				else
					S->pop();
			}
		}
		return S->empty() ? true : false;
	}

public:
/////////////////////////////////////////////////////////////


	Palindromes() {
		UI = "";	// Initialize string to EMPTY
		infile.open("string.txt");
		outfile.open("string.txt");
	}

	/*
	*@FunctionName: ProcessExpression
	*@Description:
	*			Announces whether string is balanced or not.
	*@Params:
	*			S - initialize stack
	*@Returns:
	*			void
	*/
	void ProcessExpression(string input) {
		S = new Stack(input.length() + 2);
		
		if (StackBal(input)) {
			cout << "Parantheses Are Balanced\n";
			outfile << "Parantheses Are Balanced\n";
		}
		else {
			cout << "Parantheses Are NOT Balanced\n";
			outfile << "Parantheses Are NOT Balanced\n";
		}
		return;
	}

	/*
	*@FunctionName: GetInput
	*@Description:
	*			Console interaction with user to gather string input
	*@Params:
	*			
	*@Returns:
	*			void
	*/
	void GetInput() {
		int NumOfInput = 1;
		
		cout << " - Enter 10 consecutive strings -" << endl;
		outfile << "- Enter 10 consecutive strings -" << endl;

		// Gathers input for 10 strings from user
		for (int i = 0; i < 10; i++) {
			cout << NumOfInput << ". ";
			outfile << NumOfInput << ". ";
			getline(cin, UI);
			outfile << UI << '\n';
			ProcessExpression(UI);

			NumOfInput++;
		}
	}
};

int main() {
	Palindromes P;
	
	P.GetInput();
}