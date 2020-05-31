#include<iostream>
#include <cmath>
using namespace std;

int minJumps(int n)
{
	int a, count = 0;

	do {
		a = (int )log2(n);
		n = n - (1 << a);
		++count;
	} while (n > 0);

	return count;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cout << minJumps(n) << endl;
	}	
	return 0;
}
