#include<iostream>
using namespace std;

int lower_bound(int a[], int n, int k)
{
	int s, e, mid;
	int lb = -1;

	s = 0;
	e = n - 1;

	while (s <= e)
	{
		mid = (s + e) >> 1;

		if (a[mid] == k){
			lb = mid;
			e = mid - 1;
		}

		else if (a[mid] > k)
			e = mid - 1;
		
		else if (a[mid] < k)
			s = mid + 1;
	}

	return lb;
}

int upper_bound(int a[], int n, int k)
{
	int s, e, mid;
	int ub = -1;

	s = 0;
	e = n - 1;

	while (s <= e)
	{
		mid = (s + e) >> 1;

		if (a[mid] == k){
			ub = mid;
			s = mid + 1;
		}

		else if (a[mid] > k){
			e = mid - 1;
			continue;
		}

		else if (a[mid] < k){
			s = mid + 1;
		}
	}
	return ub;
}

int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int k, lb, ub;
		cin >> k;
		lb = lower_bound(a, n, k);
		ub = upper_bound(a, n, k);
		
		cout << lb << " " << ub << endl;
	}

	return 0;
}
