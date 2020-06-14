#include <iostream>
using namespace std;


int pow(int a, int n)
{
    // Base case
    if (n == 0)
        return 1;

    int result = a * pow(a, n - 1);     

    return result;
}


// O(log n) -> far more optimized aproach to calculate powers
int powOptimized(int a, int n)
{
    if (n == 1)
        return a;

    int smallAns = powOptimized(a, n/2);
    smallAns *= smallAns;
    
    if (n & 1)
        return a * smallAns;           //i.e. 2^(n/2) = 2 * (2^(n/2))^2

    else
        return smallAns;
}


int main()
{
    int a, n;

    cin >> a >> n;

    //int result = pow(a, n);
    int result = powOptimized(a, n);
    cout << result << endl;
}
