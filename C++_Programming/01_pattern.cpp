/*

1
11
111
1001
11111
100001
1111111
10000001

For odd rows - print all 1's
For even rows- In the first and last position, print 1 else 0
*/

#include <iostream>
using namespace std;

int main()
{
	int height, OF = 0;

	cout << "Enter the height of the pattern: ";
	cin >> height;

	for (int i = 1; i <= height; ++i)
	{
		OF = 0;
		if (i & 1) OF = 1;			// Setting the Odd Flag (OF) to 1 if 'i' is an odd number

		for (int j = 1; j <= i; ++j)
		{
			if ((j == 1) || (j == i)) {
				cout << '1'; 
				continue;
			}
			
			if (OF) cout << '1';
			else cout << '0';
		} 
		
		cout << "\n";
	}


	return 0;
}

