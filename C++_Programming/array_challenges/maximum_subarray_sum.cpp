#include<iostream>
#include <climits>
using namespace std;

// Kadane's Algorithm
long maxSubarraySum(int *a, int n)
{
	int ssf = 0;			// Sum So Far
	int res = INT_MIN;		// Maximum subarray sum

	for (int i = 0; i < n; ++i)
	{
		ssf = max(a[i], ssf + a[i]);
		res = max(ssf, res);
	}	

	return res;
}

int main() {
	unsigned int T, n;
	cin >> T;

	// Take T inputs
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		int a[n];
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		
		int result = maxSubarraySum(a, n);
		cout << result << endl;
	}
	return 0;
}
