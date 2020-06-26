#include<iostream>
#include <vector>
using namespace std;

void getIndices(int a[], int i, int n, int k, vector<int> &v)
{
	if (i == n)
		return;

	if (a[i] == k)
		v.push_back(i);
	
	getIndices(a, i + 1, n, k, v);
}

int main() {
	int n, m;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	cin >> m;				// No. whose indices are to find in a[]

	vector<int> v;

	getIndices(a, 0, n, m, v);

	for (auto x: v)
		cout << x << " ";


	return 0;
}
