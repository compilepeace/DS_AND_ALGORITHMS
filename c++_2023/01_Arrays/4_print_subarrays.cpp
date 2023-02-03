#include <iostream>
using std::cout;

/*
    time complexity: O(n^3)
    brute-force method to find & print all subarrays in a input array
*/
void printSubarrays (int arr[], int size)
{
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            // print subarray from ith --> jth element
            for (int k = i; k <= j; ++k){
                cout << arr[k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main ()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(array)/sizeof(int);
    
    printSubarrays(array, size);
}