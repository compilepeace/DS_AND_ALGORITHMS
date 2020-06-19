// We have to maximize the profit

#include <iostream>
using namespace std;


int profit(int w[], int p[], int n, int c)
{
    // If bag is full or there are no items left to store
    if (c == 0 or n == 0){
        return 0;
    }

    int p1, p2;
    p1 = p2 = 0;

    if (w[n-1] <= c)
        p1 = p[n - 1] + profit(w, p, n - 1, c - w[n-1]);       // profit when (n-1)th item is included
    
    p2 = profit(w, p, n - 1, c);                           // profit when (n-1)th item is excluded

    return max(p1, p2);
}


int main()
{
    int wt[]    = {1, 2, 3, 5};
    int price[] = {40, 20, 30, 100};

    int n = 4;
    int capacity = 7;

    int ans = profit(wt, price, n, capacity);
    cout << ans << endl;
}
