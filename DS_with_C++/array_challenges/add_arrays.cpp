#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, m; 
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	cin >> m;
	int b[m];
	for (int j = 0; j < m; ++j)
		cin >> b[j];

	int i = n - 1;
	int j = m - 1;
	int c = 0;
	vector<int> v;

    // Add both the arrays ('a' & 'b'), and store the result in vector 'v'
	while (i >= 0 or j >= 0)
	{
		int v1 = (i >= 0) ? a[i--]: 0;
		int v2 = (j >= 0) ? b[j--]: 0;

		int value = v2 + v1 + c;
		v.push_back(value % 10);
		c = value / 10;
	}

    // Include last addition's carry in vector if it is not zero
    if (c != 0)
		v.push_back(c);
	
    // Reverse the output vector
	reverse(v.begin(), v.end());
	

    // Print the output
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout << "END" << endl;

	return 0;
}
