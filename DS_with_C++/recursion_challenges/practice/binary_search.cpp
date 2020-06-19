#include <iostream>
using namespace std;


int bs(int a[], int s, int e, int k)
{
    int index = -1;

    int mid = ( s + e ) >> 1;

    // 2 base cases
    if ( s > e)
        return -1;
    if ( a[mid] == k )
        return mid;


    // Induction hypothesis
    if ( a[mid] < k )
        index = bs(a, mid + 1, e, k);

    else
        index = bs(a, s, mid - 1, k);

    return index;
}


int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;

    cin  >> n;

    int index = bs(a, 0, 10, n);
    if (index != -1)
        cout << "Found @ " << index << endl;

    else
        cout << n << " Not found\n";
}
