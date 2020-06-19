// Modi visits only prime numbers in range [a, b] (inclusive range)

#include<iostream>
#include <vector>
using namespace std;

#define INT_MAX 1000000
#define ll long long


vector<long long> getPrimeSeive(int n, int c[])
{
    vector<bool> a(n + 1);
    a.clear();
    vector<long long> result;
	a[2] = 1;
    result.push_back(2);        // v[2] is a prime

    // Set all odd indices as prime
    for (int i = 3; i < n; i += 2)
        a[i] = 1;

    for (int i = 3; i < n; i += 2)
    {
        // If a[i] is prime, mark all its multiples as 0
        if (a[i] == 1){
            result.push_back(i);

            // Here, typecasting (int*int) into (long long) is important, without it we get a SIGSEGV
            for (ll j = (ll )i*i; j < n; j += i)
                a[j] = 0;
        }
    }

	// Preparing a cumulative sum array
	int sum = 0;
	for (int i = 2; i <= n; ++i){
		
		// If 'i' is prime
		if (a[i] == 1)
			++sum;
		c[i] = sum;
	}

    return result;
}

int main() {

	int t;
	cin >> t;

	// Creating a cummulative sum array from primes array
	int c[INT_MAX + 1] = {0};

	// Get a vector storing all the prime numbers till INT_MAX
	vector<long long> primes = getPrimeSeive(INT_MAX, c);
	
	for (int i = 0; i < t; ++i){

		long long a, b;
		cin >> a >> b;

		// The number of countries PM Modi will visit is given by
		// prime numbers in range of [a, b]
		cout << c[b] - c[a - 1] << endl;
	}

    return 0;
}
