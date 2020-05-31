#include<iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i;
		int cur = a[j--];		// Now a[i] becomes a hole

		while ( j >= 0 )
		{
			if (cur < a[j])
				a[j + 1] = a[j];
			
			else{
				a[j + 1] = cur;
				break;
			}
			--j;
		}

		if (j < 0)
			a[0] = cur;

	}
}

int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	insertion_sort(a, n);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

	return 0;
}
