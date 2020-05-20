#include<iostream>
#include <vector>
using namespace std;

void pascalTriangle(int n)
{
	vector<int> v(1, 1);

	for (int i = 0; i < n; ++i)
	{
		// Print spaces
		for (int s = 0; s < (n - i - 1); ++s)
			cout << '  ';

		

		// Print numbers
		for (int j = 0; j < v.size(); ++j)
			cout << v[j] << ' ';
	}
}

int main() {
	int n;
	cin >> n;

	pascalTriangle(n);

	return 0;
}
