/*
 * Inversion count : 1 5 2 6 3 0 => 8
 * i.e. an inversion is formed if (i < j) and a[i] > a[j]
 * 
 * (1, 0) (5, 2) (5, 3) (5, 0) (2, 0) (6, 3) (6, 0) (3, 0)
*/

#include <iostream>
using namespace std;


// While merging, we take care of the cross inverions (i.e. inversions accross 2 halves
int merge(int a[], int s, int e)
{
    int i, j, k, mid, size, count = 0;
    
    size = e - s + 1;
    int temp[size];

    mid = (s + e) >> 1;
    i = s;
    j = mid + 1;
    k = 0;

    while (i <= mid and j <= e){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];    
        }
        else{
            count += mid - i + 1;       // All the elements [i, mid] will be greater than a[j] 
            temp[k++] = a[j++];
        }
    }
    
    while ( i <= mid )
        temp[k++] = a[i++];

    while ( j <= e )
        temp[k++] = a[j++];

    
    // Puting back sorted array from temp[] to a[]
    for (int i = s, k = 0; i <= e; ){
        a[i++] = temp[k++];
    }

    return count;                       // return cross inversion count
}


int ciHelper(int a[], int s, int e)
{
    int mid = (s + e) >> 1;

    // Base case
    if ( s >= e )
        return 0;

    int x = ciHelper(a, s, mid);         // count inversions between first half
    int y = ciHelper(a, mid + 1, e);     // count inversions between second half
    int z = merge(a, s, e);              // count inversion between two halves
    
    return (x + y + z);
}

int countInversions(int a[], int size)
{
    int ans = ciHelper(a, 0, size - 1);
    return ans;
}


int main()
{
    int a[] = {1, 5, 2, 6, 3, 0};
    int size = sizeof(a)/sizeof(int);

    cout << countInversions(a, size) << endl;
}
