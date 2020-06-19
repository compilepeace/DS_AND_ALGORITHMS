#include <iostream>
using namespace std;

int main()
{
    int i = 0, j = 0;

    while (i < 10 or j < 10)
    {
        cout << i << ": " << j << endl;
        ( i & 1 ) ? j++: i++;
 
    }
 }
