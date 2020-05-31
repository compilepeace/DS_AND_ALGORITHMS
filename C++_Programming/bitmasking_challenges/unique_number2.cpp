// All the numbers are present twice except for 2 numbers which is only present once

#include<iostream>
using namespace std;

bool isBitSet(int a, int pos)
{
	int mask = 1 << pos;
	return (a & mask) > 0 ? true: false;
}


void printUniqueNumbers2(int a[], int n)
{
	int result = 0;

	// Result will store the xored value of 2 unique numbers
	for(int i = 0; i < n; ++i)
		result = (result ^ a[i]);

	// Find and store the 1st set bit of result in pos
	int temp = result;
	int pos = 0;
	while ( !(temp & 1) ){
		++pos;
		temp = temp >> 1;
	}

	// There will be odd number of elements having bit set at 'pos'
	// XORing all these numbers will leave us with one of the 2 unique numbers
	int unique1 = 0, unique2 = 0;
	for (int i = 0; i < n; ++i)
	{
		bool status = isBitSet(a[i], pos);
		if (status)
			unique1 = unique1 ^ a[i];
	}

	unique2 = result ^ unique1;		// a^b=c is same as a^c=b or b^c=a

	cout << min(unique1, unique2) << " " << max(unique1, unique2) << endl;
}

int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	printUniqueNumbers2(a, n);

	return 0;
}
