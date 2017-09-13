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
	char ch;

	ifstream infile;
	ofstream outfile;
	
	/*
	*@FunctionName: processUI
	*@Description:
	*			Determines input string from user and isolates
				the parantheses into the stack.
	*@Params:
	*			string input = UI (input from user STDIN)
	*@Returns:
	*			stack empty (true/false)
	*/

	bool processUI(string input) {
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
		infile.open("infile.txt");
		outfile.open("outfile.txt");
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
		
		if (processUI(input)) {
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
	void GetUI() {
		int NumOfInput = 0;
		int count = 1;
		
		cout << "How many lines of input do you have? ";
		cin >> NumOfInput;
		cout << " - Enter " << NumOfInput << " consecutive strings -" << endl;
		outfile << "- Enter " << NumOfInput << " consecutive strings -" << endl;
		cin.ignore();	// prevents reading in \n from previous cin (stupid C++)

		//Gathers input for strings from user
		while (count <= NumOfInput) {
			cout << count << ". ";
			outfile << count << ". ";
			getline(cin, UI);
			outfile << UI << '\n';
			ProcessExpression(UI);
			count++;
		}
	}

	/*
	*@FunctionName: processBalanced
	*@Description:
	*			Announces whether string (from infile) is balanced or not.
	*@Params:
	*			bool bal - readInFile (true/false)
	*			string UI - Global (Line being processed char by char)
	*			int count - the number of lines it has processed
	*@Returns:
	*			void
	*/
	void processBalanced(bool bal, string UI, int count) {
		cout << count << ". " << UI;
		outfile << count << ". " << UI;

		if (count != 0) {
			if (bal) {
				cout << "Parantheses Are Balanced\n";
				outfile << "Parantheses Are Balanced\n";
			}
			else {
				cout << "Parantheses Are NOT Balanced\n";
				outfile << "Parantheses Are NOT Balanced\n";
			}
		}
		return;
	}

	/*
	*@FunctionName: processInFile
	*@Description:
	*			Determines input string from infile and isolates
	*			the parantheses into the stack.
	*@Params:
	*			none
	*@Returns:
	*			void
	*/
	void processInfile() {
		int count = 0;

		do {
			S = new Stack(100);
			bool balanced = true;
			count++;

			while (infile.get(ch)) {
				UI = UI + ch;

				if (ch == '(')
					S->push(ch);
				else if (ch == ')') {
					if (!S->empty())
						S->pop();
					else
						balanced = false;
				}
				else if (ch == '\n')
					break;
			}

			if (!balanced) {
				count = 0;
				balanced = true;

				processBalanced(balanced, UI, count);
			}
			else
				processBalanced(S->empty(), UI, count);

			UI = "";
		} while (!infile.eof());
	}

	/*
	*@FunctionName: Menu
	*@Description:
	*			Console interaction with user to gather input
	*@Params:
	*
	*@Returns:
	*			void
	*/
	void Menu() {
		int selection;

		cout << "Palidromes Program by Brice Allard\n\n";
		cout << "1. Enter expression from keyboard\n";
		cout << "2. Use pre-defined input file\n";
		cout << "Choice (1-2): ";
		cin >> selection;
		cout << endl;

		if (selection == 1)
			GetUI();
		else if (selection == 2)
			processInfile();
		else
			cout << "Invalid selection, Good-bye!\n";

		system("pause");
	}
};

int main() {
	Palindromes P;
	
	P.Menu();
}