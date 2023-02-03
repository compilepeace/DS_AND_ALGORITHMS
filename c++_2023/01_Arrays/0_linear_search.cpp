#include <iostream>
using std::cout;

/*
    time complexity: O(n)
    linear sweep on input array to find 'key' element
*/
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i){
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main (int argc, char *argv[])
{
    int array[] = {90, 80, 10, 30, 20, 60};
    int size = sizeof(array)/sizeof(int);
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <number>\n";
        return 1;
    }

    int key = std::stoi(argv[1]);
    int idx = linearSearch(array, size, key);
    if (idx < 0)
        cout << key << ": could not be found\n";
    else
        cout << key << ": found at index " << idx << "\n"; 
}