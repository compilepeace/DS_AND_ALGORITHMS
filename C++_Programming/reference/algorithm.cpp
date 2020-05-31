#include <iostream>
#include <algorithm>
using namespace std;


/*
find()          - Returns an iterator to first occurence of key. [works in O(n)]
binary_search() - Returns a bool value of existence of key inside a container.
lower_bound()   - Returns an iterator to first element >= key.   [works in O(logn)]
upper_bound()   - Returns an iterator to first element >  key.   [works in O(logn)]

sort()             - Sorts a container (can specify a comparator too) 
rotate()           - Rotates an array via a value of reference (mid argument) 
next_permutation() - Gives the next permutation of next container elements (such as array)
reverse()          - reverses an array/subarray  

swap()          - swaps 2 variables
min()           - Returns the minimum of 2 elements
max()           - Returns the maximum of 2 elements

*/


bool compare(int a, int b)
{
    return a > b;
}

int main()
{

   int a[] = {11, 22, 33, 33, 33, 44, 55};
   int n = sizeof(a)/sizeof(int);
   
   int key, index;


// find() - returns an iterator using linear search ----------------------------------- 
   key = 33;
   auto it = find(a, a + n, key);
   index = it - a;
//-------------------------------------------------------------------------------------


// binary_search() - returns 'bool' value if no. is present ---------------------------
    bool truth = binary_search(a, a + n, key);
    if (truth)
        cout << "Key: " << key << " present\n";
    else
        cout << "Key: " << key << " not present\n";
//------------------------------------------------------------------------------------


// lower_bound() and upper_bound() ---------------------------------------------------

    auto it1 = lower_bound(a, a + n, key);
    cout << "lower_bound of " << key << " is: " << it1 - a << endl;

    auto it2 = upper_bound(a, a + n, 35);
    cout << "upper_bound of 35 is: " << it2-a << endl;

    cout << "Occurence of key(" << key << "): "
         << upper_bound(a, a+n, key) - lower_bound(a, a + n, key)
         << endl;
//-----------------------------------------------------------------------------------


// sort() ---------------------------------------------------------------------------

    char b[] = "abhinav";
    sort(b, b + 7, compare);
    cout << b << endl;
//----------------------------------------------------------------------------------


// rotate()  -----------------------------------------------------------------------

    int c[] = {1, 2, 3, 4, 5};
    rotate(c, c + 2, c + 5);            // Rotate about 2nd element
    for (auto i: c) cout << i << ", ";
    cout << endl;

//----------------------------------------------------------------------------------


// next_permutation() -------------------------------------------------------------

    int d[] = {1, 2, 3};
    cout << "Permutations - " << endl;
    for (int i = 0; i < 6; ++i){
        next_permutation(d, d + 3);
        for (auto j: d)
            cout << j << ", ";
        cout << endl;
    }
//----------------------------------------------------------------------------------

// reverse() -----------------------------------------------------------------------

    char e[] = "abhinav";
    reverse(e, e + 7);
    cout << e << endl;
//----------------------------------------------------------------------------------

    int var1 = 10, var2 = 20;
    int large = max(var1, var2);
    int small = min(var1, var2);
    swap(var1, var2);



}
