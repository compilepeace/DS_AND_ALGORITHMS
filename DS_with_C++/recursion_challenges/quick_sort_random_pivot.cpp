#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Returns a pivot index whose left hand side contains all elements smaller than the pivot and right 
// side contains all elements larger than pivot element.
int partition(int a[], int s, int e)
{
	srand(time(0));
    int pivotIndex = (rand() % (e - s + 1)) + s;
    int pivot = a[pivotIndex];

	swap(a[pivotIndex], a[e]);                  // Place the pivot at the end 'e'
    
	int k = s;

    // Start placing all the elements less than pivot (at positions starting from 0th index)
    for (int i = s; i < e; ++i){
        if (a[i] < pivot)
            swap(a[k++], a[i]);
    }

    // swap pivot (a[e]) to its intended position
    swap(a[e], a[k]);

    return k;
}

void quickSort(int a[], int s, int e)
{
    // Base case: for 0 or 1 element
    if ( s >= e )
        return;

    int p = partition(a, s, e);                 // Partition and get the pivot index
    quickSort(a, s, p - 1);                     // Apply quickSort on left hand side of pivot
    quickSort(a, p + 1, e);                     // Apply quickSort on right hand side of pivot

}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    quickSort(a, 0, n-1);

    for (int i=0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}




