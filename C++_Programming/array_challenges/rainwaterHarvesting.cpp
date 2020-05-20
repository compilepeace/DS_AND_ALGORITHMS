#include<iostream>
using namespace std;

int rainwaterHarvesting(int *a, int n)
{
	// Arrays storing max value encountered from left to right and vice versa
	int l2r[n], r2l[n];
	int max_l2r = 0, max_r2l = 0;
	int smaller, sum = 0;

	for (int start = 0, end = n - 1; start < n; ++start, --end)
	{
		max_l2r = max(a[start], max_l2r);
		max_r2l = max(a[end], max_r2l);

		l2r[start] = max_l2r;
		r2l[end] = max_r2l;	
	}

	for (int i = 0; i < n; ++i)
	{
		int smaller = min(l2r[i], r2l[i]);
		sum += smaller - a[i];
	}

	return sum;
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	int result = rainwaterHarvesting(a, n);
	cout << result;

	return 0;
}
