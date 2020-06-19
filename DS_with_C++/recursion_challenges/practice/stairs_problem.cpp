#include <iostream>
using namespace std;


int ways(int n)
{
    // Base case
    if ( n < 0 )
        return 0;
    if ( n == 0 )
        return 1;

    int x = 0, y = 0, z = 0;

    x = ways(n - 1);
    y = ways(n - 2);
    z = ways(n - 3);

    return (x + y + z);
}


int main()
{
    int n;
    cin >> n;       // No. of stairs

    int ans = ways(n);
    cout << ans << endl;
}
