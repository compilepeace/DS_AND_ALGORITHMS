#include<iostream>
#include <cmath>
using namespace std;

bool check(long long int n, int k, int x)
{
	return (pow(x, k) <= n) ? true: false;
} 

int greatestInt(long long int n, int k)
{
	long long int s = 0;
	long long int e = n;
	int ans = 0;

	while (s <= e)
	{
		long long int mid = (s + e)/2;
		bool status = check(n, k, mid);
		
		if (status == true)
		{
			ans = mid;
			s = mid + 1;
		}

		else
			e = mid - 1;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; ++z)
	{
		long long int n;
		int k;
		cin >> n >> k;
		int res = greatestInt(n, k);
		cout << res << endl;
	}
	return 0;
}
