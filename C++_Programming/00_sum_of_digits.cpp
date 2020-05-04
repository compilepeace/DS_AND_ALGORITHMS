#include <iostream>
using namespace std;

int main()
{
	int digit, n, sum = 0;

	cout << "Enter a number: ";
	cin >> n;

	while (n > 0)
	{
		digit = n % 10;
		sum += digit;
		n = n/10;
	}

	cout << "Sum of digits: " << sum << "\n";
	
	return 0;
}
