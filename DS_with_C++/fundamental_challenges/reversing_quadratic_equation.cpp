#include<iostream>
#include <cmath>
using namespace std;

void printRoots(float a, float b, float c){
	
	float d = (b*b) - (4*a*c);
	float root1, root2;

	if (d > 0)
	{
		cout << "Real and Distinct" << endl;
		root1 = (-b + sqrt(d)) / (2*a);
		root2 = (-b - sqrt(d)) / (2*a);
		cout << (int )root2 << ' ' << (int )root1;
	}

	if (d == 0)
	{
		cout << "Real and Equal" << endl;
		root1 = (-b + sqrt(d)) / (2*a);
		root2 = (-b - sqrt(d)) / (2*a);
		cout << (int )root2 << ' ' << (int )root1;
	}

	if (d < 0)
	{
		cout << "Imaginary" << endl;
	}
	
}

int main() {

	float a, b, c;

	cin >> a >> b  >> c;
	printRoots(a, b, c);

	return 0;
}
