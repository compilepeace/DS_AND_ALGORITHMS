#include<iostream>
using namespace std;

// Search k and output index at which it is found or -1 if k is not found
int binarySearch(int a[], int n, int k)
{
	int s, e, mid;
	int ans = -1;

	s = 0;
	e = n - 1;

	while (s <= e)
	{
		mid = (s + e) >> 1;

		if (a[mid] == k){
			ans = mid;
			return ans;
		}

        // There are 2 ranges in which k could lie
		if (a[mid] < k){
			if (a[e] < k)
				e = mid - 1;
			else
				s = mid  + 1;
		}

        // There are 2 ranges in which k could lie
		if (a[mid] > k){
			if (a[s] < k)
				e =  mid - 1;
			else
				s = mid + 1;
		}
	}

	return ans;
}

int main() {
    int n, k;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cin >> k;

    cout << binarySearch(a, n, k);

    return 0;
}

