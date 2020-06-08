#include<iostream>
using namespace std;

int findPivot(int a[], int n)
{
	int s, e, mid, ans = -1;
	s = 0;
	e = n - 1;

	while (s <= e)
	{
		mid = (s + e) >> 1;

		if ( a[mid] < a[s] )
			e = mid - 1;
		
		else if (a[mid] >= a[s]){
			ans = mid;
			s = mid + 1;
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	int a[n];	

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << findPivot(a, n);

	return 0;
}
