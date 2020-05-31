#include<iostream>
using namespace std;

void printPattern(int n)
{
	for (int j = n; j > 0 ; --j)
	{
		int i;
		// Print numbers
		for (i = 1; i <= (n - j + 1); ++i)
			cout << i;
		
		for (int k = i; k <=n; ++k)
			cout << "*";

		cout << endl;
	}
}

int main() {

	int n;
	cin >> n;

	printPattern(n);
	return 0;
}
