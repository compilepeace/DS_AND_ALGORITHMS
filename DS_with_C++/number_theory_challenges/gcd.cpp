#include<iostream>
#include <algorithm>
using namespace std;


int gcd(int a, int b)
{
	if (b < a)
		swap(a, b);

	while (b % a){
		int a_ = a;
		int b_ = b;
		
		b = a_;
		a = b_ % a_;
		
	}

	return a;
}

int main() {
	int a, b;

	cin >> a >> b;

	//cout << __gcd(a, b);
	cout << gcd(a, b);
	
	return 0;
}
