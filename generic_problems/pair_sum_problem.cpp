#include <iostream>

using namespace std;

void printPairSum(int a[], int n, int k)
{
	int i = 0, j = n - 1, sum = 0;

	while (i < j){
		sum = a[i] + a[j];
		if (sum < k)
			++i;
		
		else if (sum > k)
			--j;

		else {
			cout << a[i] << " ~ " << a[j] << endl;
			--j;
			++i; 
		}
	}	
}


int main()
{
	int n, k;

	cout << "Enter the number of elements in the array and value of k: ";
	cin >> n >> k;

	int a[n] = {0};

	cout << "Enter the array with " << n << " elements: ";
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	printPairSum(a, n, k);
}
