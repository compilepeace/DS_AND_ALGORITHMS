#include<iostream>
#include <climits>
using namespace std;

// Start iterating from 'start' index and increment its value 'n' times
long long maxCircularSum(long long a[], int n, int start)
{
	long long ssf = 0, max_sum = INT_MIN;
	for (int counter = 0, i = start; counter < n; ++counter, ++i)
	{
		i = i % n;			// keep value in range of [0, n)
		ssf = max(a[i], ssf + a[i]);
		max_sum = max(ssf, max_sum);
	}
	
	return max_sum;
}

int main() {

	long long value = 0; ;
	int t, n;

	cin >> t;

	for (int j = 0; j < t; ++j){
		long long result = INT_MIN;
		cin >> n;
		long long a[n];
		
		// Take input in a[]
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		
		// iterate over the array deciding which one is the starting index
		for (int i = 0; i < n; ++i)
		{
			value = maxCircularSum(a, n, i);
			result = max(value, result);
		}
		cout << result << endl;
	}
	

	return 0;
}
