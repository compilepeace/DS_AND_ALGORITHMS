#include<iostream>
using namespace std;

void printPattern(int n)
{
	int spaces = (n/2) * 4;
	int btwn_spaces = 3;

	for (int i = 1; i <= (n/2) + 1; ++i)
	{
		// Print spaces
		for (int s = 0; s < spaces; ++s)
			cout << ' ';
		spaces -= 4;

		// Print numbers
		for (int j = i; j >= 1; --j)
			cout << j << ' ';
		
		if (i != 1){
			// Print spaces
			for (int s = 0; s < (btwn_spaces - 1); ++s)
				cout << ' ';
			btwn_spaces += 4;

			// Print numbers in reverse
			for (int j = 1; j <= i; ++j)
				cout << j << ' ';
		}

		cout << endl;
	}

	spaces = 4;
	btwn_spaces -= 8;
	for (int i = n/2; i >= 1; --i)
	{
		// Print spaces
		for (int s = 0; s < spaces; ++s)
			cout << ' ';
		spaces += 4;

		// Print numbers in reverse order
		for (int j = i; j >= 1; --j)
			cout << j << ' ';
		
		if (i != 1){
			// Print spaces
			for (int s = 0; s < (btwn_spaces - 1); ++s)
				cout << ' ';
			btwn_spaces -= 4;

			// Print numbers in reverse
			for (int j = 1; j <= i; ++j)
				cout << j << ' ';
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the height of double arrow pattern: ";
	cin >> n;

	printPattern(n);

	return 0;
}
