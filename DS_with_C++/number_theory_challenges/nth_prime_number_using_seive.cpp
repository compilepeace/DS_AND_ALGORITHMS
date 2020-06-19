#include<iostream>
#include <vector>
using namespace std;

#define INT_MAX 100000000
#define ll long long


vector<long long> getPrimeSeive(int n)
{
    vector<bool> a(n + 1);
    a.clear();
    vector<long long> result;

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

    return result;
}

int main() {

    int n;
    cin >> n;

    // Get a vector storing all the prime numbers till INT_MAX
    vector<long long> primes = getPrimeSeive(INT_MAX);

    // Get nth prime number
    cout << primes[n - 1];

    return 0;
}


