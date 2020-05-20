#include<iostream>
using namespace std;

void printPattern(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		// Print spaces
		for (int s = 0; s < (n - i); ++s)
			cout << ' ';

		// Print star
		if (i == 1 or i == n){
			for (int j = 1; j <= n; ++j)
				cout << '*';
		}
		else{
			cout << '*';
			for (int s = 0; s < n - 2; ++s)
				cout << ' ';
			cout << '*';
		}
		cout << '\n';
	}
}

int main() {
	int n;
	cout << "Enter the height of rhombus: ";
	cin >> n;

	printPattern(n);

	return 0;
}
