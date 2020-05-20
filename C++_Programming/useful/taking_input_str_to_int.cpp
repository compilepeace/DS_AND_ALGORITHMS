#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;


int main()
{
	string s = "1234";
	stringstream abhi(s);
	int n = 0;


	// <1>: Using stringstream to convert string -> integer
	abhi >> n;
	cout << "last digit : " << (1234 % 10) << endl;
	
	// <2>: Using strtoi() to convert string -> integer
	const char *number = "5678";
	n = stoi(number);
	cout << "last digit: " << (n % 10) << endl;

	
	// <1>: Taking a line input with delimiter of '\n'
	string s1;
	getline(cin, s1, '\n');
	cout << s1;	

	// <2>: Taking a character array input
	char array[10];
	cout << "\nEnter a character array input(" << sizeof(array) << "): ";
	cin.getline(array, sizeof(array));
	cout << array;
}
