#include <iostream>
using namespace std;


void merge(int a[], int s, int e)
{
    int n = (e - s + 1);
    int temp[n];
    int mid = (s + e) >> 1;
    
    int i = s;
    int j = mid + 1;
    int k = 0;

    // run the loop until both i and j reaches end of the two arrays
    while ( i <= mid and j <= e){
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Get the remaining elements of 1st array (if any) into temp[] 
    while (i <= mid){
        temp[k++] = a[i++];
    }

    // Get the remaining elements of 2nd array (if any) into temp[]
    while(j <= e){
        temp[k++] = a[j++];
    }


    // copy the elements from temp[] back to a[]
    for (int i = 0, j = s; i < n and j <= e; )
        a[j++] = temp[i++];
}


void sortHelper(int a[], int s, int e)
{    
    int mid = (s + e) >> 1;

    // Divides until start >= end
    if (s >= e)
        return;

    // It divides the array into 2 halves
    sortHelper(a, s, mid);
    sortHelper(a, mid + 1, e);
    merge(a, s, e);
}


void mergeSort(int a[], int n)
{
    int s = 0;
    int e = n - 1;

    sortHelper(a, s, e);
}


int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(int);

    mergeSort(a, n);
   
    for (auto i: a)
        cout << i << " ";
}
