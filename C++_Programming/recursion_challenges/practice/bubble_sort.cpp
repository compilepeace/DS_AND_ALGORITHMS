#include <iostream>
using namespace std;

void sort(int a[], int n)
{
    if ( n == 1 )
        return;

    for (int i = 0; i <= n - 2; ++i)
    {
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    }

    sort(a, n - 1);
}

// This function is completely recursive
void sortR(int a[], int n, int j = 0)
{
    // base case
    if ( n == 1 )
        return;

    if ( j < (n - 1) ){
        if (a[j] > a[j + 1])
            swap(a[j], a[j + 1]);
        return sortR(a, n, ++j);
    }
  
    // This means this pass is done, decrease the size of array by 1 and reset j = 0
    sortR(a, n - 1, 0);
}

int main()
{
    int a[] = {2, 5, 1, 3, 4};
    int size = sizeof(a)/sizeof(int);

    sortR(a, size);

    for (auto i: a)
        cout << i << " ";
        cout << endl;
}
