#include<iostream>
using namespace std;

void printPattern(int n)
{
	int value = n/2;
	
	for (int i = 0; i < (n/2 + 1); ++i)
	{
		// For first
		if (i == 0){
			// Print stars
			for (int j = 1; j <= n; ++j)
				cout << '*' << '\t';			
		}
		else {
			// Print stars
			for (int j = 1; j <= value; ++j)
				cout << '*' << '\t';
			
			// Print spaces
			for (int s = 1; s <= (n - 2*value); ++s)
				cout << ' ' << '\t';

			// Print stars
			for (int j = 1; j <= value; ++j)
				cout << '*' << '\t';
			--value;
		}
		cout << "\n";
	}

	value += 2;
	for (int i = 0; i < n/2; ++i)
	{
		// For last row
		if (i == n/2 - 1){
			// Print stars
			for (int j = 1; j <= n; ++j)
				cout << '*' << '\t';			
		}
		else {
			// Print stars
			for (int j = 1; j <= value; ++j)
				cout << '*' << '\t';
			
			// Print spaces
			for (int s = 1; s <= (n - 2*value); ++s)
				cout << ' ' << '\t';

			// Print stars
			for (int j = 1; j <= value; ++j)
				cout << '*' << '\t';
			++value;
		}
		cout << "\n";

	}
}

int main() {
	int n;

	cout << "Enter the height of hollow diamond (odd number): ";
	cin >> n;

	if (n & 1)
		printPattern(n);
	
	else 
		cout << "Told you: Enter an odd number !\n";
	return 0;
}
