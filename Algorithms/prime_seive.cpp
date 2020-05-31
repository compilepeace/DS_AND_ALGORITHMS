// Given a number 'n', print all prime numbers less than N
// without getting a TLE (Time Limit Exceeded) in O(N log log N)

#include <iostream>
using namespace std;


// Generates an array of prime numbers till n.
// On any array index, 1 means index is prime.
void prime_seive(int a[], int n)
{
    a[0] = a[1] = 0;
    a[2] = 1;

    // Initializing : Mark all the odd numbers as prime numbers
    for (int i = 3; i <= n; i += 2)
        a[i] = 1;

    for (int i = 3; i <= n; i += 2){
    
        // If i number is prime
        // mark all multiples of i starting from starting from i*i as not prime.  
        if (a[i] == 1){
            
            for (int j = i*i; j <= n; j += i)
                a[j] = 0;    
        }
    }   
}


int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int *a = new int[n + 1]{0};

    // Generate an array of prime numbers
    prime_seive(a, n);

    cout << "Prime numbers till " << n << " are: ";
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 1)
            cout << i << " ";
    }

    cout << endl;
}
