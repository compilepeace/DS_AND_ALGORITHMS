#include<iostream>
using namespace std;

void printPattern(int n)
{
	int spaces = n - 1;

	for (int i = 1; i <= n; ++i)
	{
		// print spaces
		for (int s = spaces; s > 0; --s)
			cout << " \t";
		--spaces;

		// print numbers
		int j = i;
		for ( ; j < 2*i; ++j)
			cout << j << '\t';
		for (int k = j - 2; k >= i; --k)
			cout << k << '\t';

		cout << endl;
	}

}

int main() {
	int n;
    cout << "Enter the height of pyramid: ";
	cin >> n;

    printPattern(n);

	return 0;
}
