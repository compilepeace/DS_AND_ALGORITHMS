#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n], b[n];

    // Taking 2 input arrays
    for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int result[2*n];
	int i = 0, j = 0, k = 0;

    // Merging both arrays
	while (i < n or j < n){
		result[k] = (a[i] < b[j]) ? a[i++]: b[j++];
		++k;
	}

    // Printing median
	cout << result[n-1];

	return 0;
}
