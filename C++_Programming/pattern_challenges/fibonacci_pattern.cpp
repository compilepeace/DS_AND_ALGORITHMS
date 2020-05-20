#include<iostream>
using namespace std;

void printPattern(int n)
{
	int ans = 0;
	int fib1 = 0;
	int fib2 = 1;

	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			// For the first row
			if (i == 1) ans = fib1;
			else if (i == 2 and j == 0) ans = fib2;
			else {
				ans = fib1 + fib2;
				fib1 = fib2;
				fib2 = ans;
			}
			cout << ans << "\t";
		}
		cout << "\n";
	}
}

int main() {
	int n;

	cout << "Enter the height of fibonacci pattern: ";
	cin >> n;
	printPattern(n);
	return 0;
}
