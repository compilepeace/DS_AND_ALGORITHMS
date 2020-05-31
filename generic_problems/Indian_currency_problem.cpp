#include <iostream>
#include <algorithm>
using namespace std;


bool compare(int a, int b)
{
    return a <= b;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
    int size = sizeof(coins)/sizeof(int);

    int n; 
    cout << "Enter the money you want: ";
    cin >> n;

    while (n > 0)
    {
        // By default returns the iterator to element >= key, therefore we write a comparator
        int index = lower_bound(coins, coins + size, n, compare) - coins - 1;
        cout << index << ": " << coins[index] << ", ";
        n -= coins[index];
    }
    cout << "END" << endl;
}
