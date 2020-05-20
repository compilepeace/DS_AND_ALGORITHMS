#include<iostream>
using namespace std;

void printPattern(int n)
{
	for (int i = 1; i <= 5; ++i)
	{
		cout << i << '\t';
		for (int j = 0; j < i - 2; ++j)
			cout << '0' << '\t';
		
		if (i != 1)
			cout << i << '\t';
		cout << endl;
	}
}


int main() {
	int n;
	cout << "Enter the height of pattern: ";	
	cin >> n;
	
	printPattern(n);

	return 0;
}
