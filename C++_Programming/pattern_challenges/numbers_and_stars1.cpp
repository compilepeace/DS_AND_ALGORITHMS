#include<iostream>
using namespace std;

void printPattern(int n)
{
	for (int j = 0; j < n; ++j)
	{
		int i;

		// Print numbers
		for (i = 1; i <= (n - j); ++i)
			cout << i << " ";
		
		// Print *
		for (int k = 0; k < (2*j - 1); ++k)
			cout << "* ";

		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;

	printPattern(n);
	return 0;
}
