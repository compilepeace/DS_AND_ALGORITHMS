#include<iostream>
using namespace std;

void printPattern(int n)
{
	int spaces = (2*n - 1);
	for (int i = n; i >= 0; --i)
	{
		// Print numbers
		for (int j = n; j >= i; --j)
			cout << j << ' ';
		
		// Print spaces
		for (int s = 0; s < spaces; ++s)
			cout << "  ";
		spaces -= 2;

		// Print numbers reverse
		int j = i;
		if (i == 0)
			j = i + 1;
		for ( ; j <= n; ++j)
			cout << j << ' ';

		cout << endl;
	}

	spaces += 4;
	for (int i = 1; i <= n; ++i)
	{
		// Print numbers
		for (int j = n; j >= i; --j)
			cout << j << ' ';
	
		// Print spaces
		for (int s = 0; s < spaces; ++s)
			cout << "  ";
		spaces += 2;

		// Print numbers in reverse
		for (int j = i; j <= n; ++j)
			cout << j << ' ';
		
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the value of n: ";
	cin >> n;

	printPattern(n);
	return 0;
}
