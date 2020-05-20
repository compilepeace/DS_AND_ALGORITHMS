#include<iostream>
using namespace std;

void printPattern(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		// If row is odd, print all 1's
		if (i & 1) {
			for (int j = 0; j < i; ++j)
				cout << '1';
		}

		// If row is even, print two 1's - one at the start and other at last. Fill 0's in between
		else {
			cout << '1';
			for (int j = 0; j < i - 2; ++ j)
				cout << '0';
			cout << '1';
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter the height of pattern: ";	
	cin >> n;

	if (n < 1)
		return 0x1;

	printPattern(n);
	return 0;
}
