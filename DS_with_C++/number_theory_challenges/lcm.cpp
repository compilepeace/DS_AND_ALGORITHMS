// Using property -->  a*b = lcm(a, b) * hcf(a, b)
// or			  -->  a*b = lcm(a, b) * gcd(a, b)


#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, result = 0;
	cin >> a >> b;

	if ( a != 0 and b != 0)
		result = (a * b)/__gcd(a, b);

	cout << result ;

	return 0;
}
