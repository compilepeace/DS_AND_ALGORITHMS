#include <iostream>
using std::cout;

/*
    time complexity: O(n^2)
    brute-force approach to find & print all pair combinations of elements in input aray.
*/
void printPair (int arr[], int size)
{
    for (int i = 0; i < size; ++i){
        for (int j = i+1; j < size; ++j){
            cout << "(" << arr[i] << "," << arr[j] << "), ";
        }
        cout << "\n";
    }
}

int main ()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(array)/sizeof(int);
    
    printPair(array, size);
}