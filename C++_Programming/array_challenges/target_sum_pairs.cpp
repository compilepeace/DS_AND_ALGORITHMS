#include<iostream>
#include <algorithm>
using namespace std;

void printPairsSumToK(int a[], int n, int k)
{
	// sort the array in ascending order
	sort(a, a+n);

	int start = 0, end = n - 1;

	while (start < end)
	{
		if (a[start] + a[end] == k){
			cout << a[start] << " and " << a[end] << endl;
			++start;
			--end;
		}

		else if (a[start] + a[end] > k)
			--end;
		
		else
			++start;
	}

}


int main() {
	int n;
	cin >> n;

	int a[n];
	int k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> k;

	if (n > 1)
		printPairsSumToK(a, n, k);


	return 0;
}
