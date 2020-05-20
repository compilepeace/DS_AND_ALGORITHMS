#include<iostream>
using namespace std;

void printPattern(int n)
{
	int h_line = n/2 + 1;
	for (int i = 1; i <= (n/2); ++i)
	{
		// Print star
		cout << '*';

		// Print spaces
		for (int s = 0; s < ((n/2) - 1); ++s)
			cout << ' ';

		// Print stars again
		if (i == 1) {
			for (int j = 0; j < h_line; ++j)
				cout << '*';
		}
		else
			cout << '*';

		cout << "\n";
	}

	for (int i = 0; i < n; ++i)
		cout << '*';
	cout << endl;

	for (int i = 1; i <= (n/2); ++i)
	{
		// Print spaces or h_line
		if (i == (n/2)){
			for (int j = 0; j < h_line - 1; ++j)
				cout << '*';
		}
		else{
			for (int s = 0; s < n/2; ++s)
				cout << ' ';
		}

		cout << '*';

		// Print spaces
		for (int s = 0; s < (n/2) - 1; ++s)
			cout << ' ';
		
		cout << "*\n";
	}
}

int main() {
	int n; 

	cout << "Enter the height of Ganesha symbol: ";
	cin >> n;
	printPattern(n);

	return 0;
}
