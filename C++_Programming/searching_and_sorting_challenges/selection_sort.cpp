#include<iostream>
#include <climits>
using namespace std;

void selectionSort(int a[], int n)
{
	for (int i = 0; i < n; ++i){
		int mini_val = INT_MAX;
		int min_index = -1;
		for (int j = i; j < n; ++j)
		{
			if (a[j] < mini_val){
				mini_val = a[j];
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);
	}
}

int main() {

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	selectionSort(a, n);

	for (int i = 0; i < n; ++j)
		cout << a[i] << endl;

	return 0;
}
