#include <iostream>

using namespace std;


int main()
{
	int value = 0, height = 0;
	
	cout << "Enter the height of pattern: ";
	cin >> height;

	for (int i = 1; i <= height; ++i)
	{
		value = (i & 1) ? 0: 1;			// value = 0 for odd and 1 for even

		for (int j = 1; j <=i; ++j)
		{
			cout << value;
			value = 1 - value;
		}

		cout << "\n";
	}
}
