#include <iostream>
#include <string>
#include <ios>				// For streamsize in cin.ignore()
#include <limits>			// For numberic_limits in cin.ignore()
using namespace std;

int main()
{
	int a;
	string s;
	
	cin >> a;

    // Simply
    cin.get();      // Gets the value '\n' pressed after giving input to 'a'


	// Flush the input buffer
	// <1> Discards the input buffer and initial whitespaces of the string 's'
	//cin >> ws;
	
	// <2> Discard all that is left in input buffer (does not work in all implementations though!
	// cin.sync()			// Doesn't work with g++ 7.3.0
	
	// <3> Discards everthing inside the input stream including '\n'. (but not initial whitespaces of s) 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	getline(cin, s, '\n');

	cout << a << endl;
	cout << s << endl;

}

