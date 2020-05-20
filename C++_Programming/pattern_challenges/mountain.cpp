#include<iostream>
using namespace std;

void printPattern(int n){

	int spaces = 2*n - 3;
	int j = 0;

	for (int i = 1; i <= n; ++i)
	{
		// Print increasing sequence
		for (j = 1; j <= i; ++j)
			cout << j << '\t';

		// Print space chars
		for (int s = spaces; s > 0; --s)
			cout << ' ' << '\t';
		spaces = spaces - 2;

		// Print decreasing sequence
		int k;
		if (i == n)
			k = j - 2;
		else
			k = j - 1;
		for ( ; k >= 1; --k)
			cout << k << '\t';
		
		// newline
		cout << endl;
	}

}

int main() {
	
	int n;
	cout << "Enter the height of mountain: ";
	cin >> n;

	if ( n == 0 )
		return 0x0;

	printPattern(n);
	
	return 0;
}
