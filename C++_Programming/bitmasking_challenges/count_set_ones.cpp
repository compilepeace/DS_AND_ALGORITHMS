#include<iostream>
using namespace std;



int getSetBits(int n)
{
	int count = 0;

	while (n > 0){
		n = n & (n - 1);
		++count;	
	}

	return count;
}


int main() {

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int a, b;
		int sum_of_set_bits = 0;

		cin >> a >> b;
		
		for (int j = a; j <=b; ++j)
		{
			// Can also use -> __builtin_popcount(j) instead of getSetBits(j);
            sum_of_set_bits += getSetBits(j);
		}

		cout << sum_of_set_bits << endl;
	}

	return 0;
}
