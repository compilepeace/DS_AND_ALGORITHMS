#include<iostream>
using namespace std;


void merge(int a[], int s, int e)
{
	int temp[e - s + 1];
	int mid = (s + e) >> 1;

	int i = s;
	int j = mid + 1;
	int k = 0;
	
	while (i <= mid and j <= e){
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= mid)
		temp[k++] = a[i++];
	
	while (j <= e)
		temp[k++] = a[j++];

	// Copy temp back to a[]
	for (int i = s, k = 0; i <= e; ++i)
		a[i] = temp[k++];

}

void mergeSort(int a[], int s, int e)
{
	if (s >= e)
		return;

	// divide
	int mid = (s + e) >> 1;

	// sort
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);

	//merge
	merge(a, s, e);
}

int main() {
	int n;
	cin  >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	mergeSort(a, 0, n-1);

	for (int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}

	return 0;
}
