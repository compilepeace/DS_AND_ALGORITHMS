#include<iostream>
using namespace std;

/*
int upperBound(int a[], int i, int n, int k)
{
    if (i == n)
        return -1;

	int index = upperBound(a, i + 1, n, k);
	if (index == -1){				// Wapas aate hue kaam check kr rhe hain
		if (a[i] == k)
			index = i;
	}

	return index;
}
*/

int upperBound(int a[], int i, int k)
{
	if (i < 0)
		return -1;

	if (a[i] == k)
		return i;

	return upperBound(a, i - 1, k);
}

int main() {
	int n, k;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	cin >> k;

	cout << upperBound(a, n - 1, k);

	return 0;
}
