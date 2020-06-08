#include<iostream>
#include <vector>
using namespace std;


void printPascal(int n)
{	
	int spaces = n - 1;

		vector<int> prev;
		prev.push_back(1);

		// From 2nd to nth row
		for (int i = 1; i <= n; ++i)
		{
			vector<int> cur;
			cur.push_back(1);

			// Print spaces
			for (int s = 1; s <= spaces; ++s)
				cout << " ";
			--spaces;

			// Print row
			cout << "1 ";			// First element

			for (int j = 1; j <= i - 2; ++j)
			{
				int e = prev[j - 1] + prev[j];
				cur.push_back(e);
				cout << e << " ";
			}

			if (i > 1){
				cout << "1 " << endl;			// last element
				cur.push_back(1);
				prev = cur;
			}
			else
				cout << endl;
		}
}

int main() {
	int n;
	cin >> n;

	if (n > 0)
		printPascal(n);

	return 0;
}
