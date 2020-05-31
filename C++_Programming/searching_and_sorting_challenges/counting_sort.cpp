#include<iostream>
#include <algorithm>
using namespace std;

// Use it only where largest element of input array is very small
void countingSort(int a[], int n)
{
	int maxi = *max_element(a, a + n) + 1;
	int bookkeeping[maxi] = {0};

	for (int i = 0; i < n; ++i){
		int index = a[i];
		bookkeeping[index] += 1;
	}


	for (int i = 0, j = 0; i < maxi; ++i){
		while (bookkeeping[i] > 0){
			a[j++] = i;
			bookkeeping[i] = bookkeeping[i] - 1;
		}	
	}
}

int main() {
	
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	countingSort(a, n);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

	return 0;
}
