#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j] >  a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int main() {

	int n;
	cin >> n;		// No. of elements in the array
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	bubbleSort(a, n);

	for (int i = 0; i < n; ++i)
		cout << a[i] << endl;

	return 0;
}
