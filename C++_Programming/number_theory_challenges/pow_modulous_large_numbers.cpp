// We have to calculate pow(a, b) % c of large numbers
// Using the property:
// (a * b) % m  ---->   ((a % m) * (b % m)) % m
// i.e. we can break down both 'a' and 'b' in range of '0 - (m-1)' before multiplying with each other,
// if all we want is for the result to lie in range of '0 - (m-1)'.

#include<iostream>
#include <cmath>
using namespace std;


int pow(int a, int b, int m)
{
	if (a >= m)
		a = (a % m);

	long long ans = a;

	// Loop runs (b-1) times
	for (int i = 1; i < b; ++i)
	{
		ans = ans * a;
		if (ans >= m)
			ans = ans % m;
	}

	return ans;
}


int main() {

	int a, b, m;
	cin >> a >> b >> m;

	int result = pow(a, b, m);

	cout << result << endl;

	return 0;
}
