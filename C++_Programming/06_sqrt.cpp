#include <iostream>

using namespace std;

int main() 
{
	int n, p;

	cout << "Enter the number and precision: ";
	cin >> n >> p;	
	
	double res = 1;
	float INC = 1.0;

	// BRUTE FORCE method	
	for (int i = 0; i < p; ++i)
	{ 
		while (res*res <= n)
		{
			fprintf(stderr, "[+] Trying : %f [%F]\n", res, INC);
			res += INC;
		}

		res = res - INC;
		INC = INC/10;
	}

	cout << "Square root of " << n << ": " << res << endl;


	return 0;
}
