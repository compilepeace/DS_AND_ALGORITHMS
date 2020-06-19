#include<iostream>
using namespace std;

void isAllowed(int n)
{
	int odd_sum = 0, even_sum = 0;
	int digit = n % 10;

	while (n != 0){
		n /= 10;

		// odd digit
		if (digit & 1) odd_sum += digit;		
		
		// even digit
		else even_sum += digit;

		digit = n % 10;
	}

	if ( (odd_sum % 3) == 0 or (even_sum % 4) == 0)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	int n = 0;

	cin >> n;

	int num;
	for (int i=0; i<n ; ++i){
		cin >> num;
		isAllowed(num); 
	}
	return 0;
}

