#include <iostream>
using std::cout;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

/*
    time complexity: O(n)
*/
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end){
        std::swap(arr[start], arr[end]);
        ++start;
        --end;
    }
}

int main ()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(array)/sizeof(int);

    printArray(array, size);
    reverseArray(array, size);
    printArray(array, size);
}