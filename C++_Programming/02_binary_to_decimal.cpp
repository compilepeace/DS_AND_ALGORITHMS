#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int b, result = 0;
	
	cout << "Enter a binary number: ";
	cin >> b;

	int power = 1;
	while ( b > 0 ) 
	{
		int digit = b % 10;
		result += digit * power;
		
		power = power * 2;	
		b = b / 10;	
	}	

	
	cout << "Decimal equivalent of " << b << " is: " << result << "\n";
	
	return 0;
}
