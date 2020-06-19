#include<iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n)
{
	int n_copy = n, count = 0, digit;

	while (n_copy != 0){
		++count;
		n_copy /= 10;
	}
	n_copy = n;

	int result = 0;
	while (n_copy != 0){
		digit = n_copy % 10;
		result += pow(digit, count);
		n_copy /= 10;
	}

	if (result == n)
		return true;
	else
		return false;

	
}

int main() {

	int n;
	cin >> n;

	bool result = isArmstrong(n);
	if (result)
		cout << "true";
	else
		cout << "false";
	return 0;
}
