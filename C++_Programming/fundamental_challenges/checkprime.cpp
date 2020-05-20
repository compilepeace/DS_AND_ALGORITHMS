#include<iostream>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i < (n/2 + 1); ++i)
		if (n % i == 0) return false;
	
	return true;
}

int main() {
	int n;

	cin >> n;
	if (n < 2)
	{
		cout << "Not Prime";
		exit(0x0);
	}

	bool result = isPrime(n);
	if (result)
		cout << "Prime";
	else
		cout << "Not Prime";
	return 0;
}
