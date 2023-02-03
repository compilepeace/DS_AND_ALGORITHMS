#include <iostream>
using std::cout;

/*
    time complexity: O(log n)
    Divide & Conquer to reduce input size by half at each iteration.
    It applies only on monotonic data structure.

    NOTE: monotonic means either non-increasing or non-decreasing
    sequence of elements in input array.
*/
int binarySearch(int arr[], int start, int end, int key)
{
    // reccursive solution - base case
    if (start > end)
        return -1;

    int mid = (start + end) / 2;        // identify mid index

    // compare mid element
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        binarySearch(arr, start, mid - 1, key);
    else
        binarySearch(arr, mid + 1, end, key);
}


int main (int argc, char *argv[])
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int size = sizeof(array)/sizeof(int);
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <number>\n";
        return 1;
    }

    int key = std::stoi(argv[1]);
    int idx = binarySearch(array, 0, size-1, key);
    if (idx < 0)
        cout << key << ": could not be found\n";
    else
        cout << key << ": found at index " << idx << "\n"; 
}