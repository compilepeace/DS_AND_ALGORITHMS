#include<iostream>
#include <algorithm>
using namespace std;


// Returns the first occurence of 'k' in a[]
int binary_search(int a[], int n, int k)
{
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e)
	{
		int mid = (s + e) >> 1;
		if (a[mid] == k){
			ans = mid;
			e = mid - 1;
		}
		
		else if (a[mid] > k)
			e = mid - 1;
		
		else
			s = mid + 1;
	}
	
	return ans;
}

int main() {
	int n, m;
	cin >> n;

	int a[n];

	// Take array as input
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort (a, a + n);

	cin >> m;
	int index = binary_search(a, n, m);
	cout << index;

	return 0;
}
