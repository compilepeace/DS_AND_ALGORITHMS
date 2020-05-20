#include<iostream>
#include <cmath>
using namespace std;

void printReverse(int n)
{
	int result = 0, count = 0, digit = 0;

	int nc = n;
	while( nc != 0){
		++count;
		nc /= 10;
	}

	while (n != 0){
		digit = n % 10;
		result += digit * pow(10, count-1);
		--count;
		n /= 10;
	}
	
	cout << result;
}


int main() {
	int n;
	cin >> n;
	printReverse(n);
	return 0;
}
