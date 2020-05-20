#include<iostream>
using namespace std;
int main() {
	int n = 0, d = 0, digit;
	int counter = 0;

	cin >> n;
	cin >> d;

	while (n != 0){
		digit = n % 10;
		n = n / 10;

		if (digit == d)
			++counter;
	} 

	cout << counter;

	return 0;
}
