#include <iostream>
using namespace std;


int mul(int a, int n)
{
    // Base case
    if (n == 0)
        return 0;

    // Induction hypothesis
    int result = a + mul(a, n - 1);
    return result;
}


int main()
{
    int a, b;
    
    cin >> a >> b;

    // A should be larger than b (for less recursive calls).
    if (a < b)
        swap(a, b);

    int result = mul(a, b);
    cout << a << " * " << b << " is " << result << endl;
}
