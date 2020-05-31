#include<iostream>
using namespace std;

#define INT_SIZE 32


void printUniqueNumber3(int a[], int n)
{
	int bits[INT_SIZE] = {0};

	for (int i = 0; i < n; ++i)
	{
		int x = a[i];

		int pos = 0;
		while (x > 0){
			if (x & 1)
				bits[pos] += 1;
			x = x >> 1;
			++pos;
		}
	}

	// Right now bits[INT_SIZE] stores the sum of all occurences of 1's at 'i' bit positions
	int ans = 0;
	for (int i = 0; i < INT_SIZE; ++i){
		if (bits[i] % 3)
			ans += 1 * (1 << i);
	}

	cout << ans << endl;

}


int main() {
	int n;
	cin >> n;
	
	if (n > 1)
	{
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
	
		printUniqueNumber3(a, n);
	}
	return 0;
}
