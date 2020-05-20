#include<iostream>
#include <cmath>
using namespace std;

/*
 * Derived using the fact that with 2 numbers given say a & b.
 * where (a > b), then 
 *          (a^2 + b^2), 2ab, (a^2 - b^2)
 * form a pythagorean tipplet.
*/
void printTriplets(long n)
{
	long long h = 0, leg = 0;
	if (n & 1){
		leg = (( n*n - 1) / 2);
		h = ((n*n + 1) / 2);
		cout << leg << ' ' << h; 
		exit(0x0);
	}

	else{
		leg = ((n*n - 4) / 4);
		h = ((n*n + 4) / 4);
		cout << leg << ' ' << h;
	}
}


int main() {
	long long n;
	cin >> n;
	if (n < 3){
		cout << "-1";
		exit(0x0);
	}
	printTriplets(n);
	return 0;
}
