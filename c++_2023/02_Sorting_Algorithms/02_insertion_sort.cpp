#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void printv(const vector<int> &v)
{
    cout << "\n";
    for (auto &x: v)
        cout << x << " ";
    cout << "\n";
}

/*
    Time complexity - O(n^2)
    There are 2 parts of input array - sorted (left) and unsorted (right)
    Before index 'i'- array is sorted, beyond index 'i'- array is unsorted.
    We start from assumption that a single element is always sorted (@ 0th index).
*/
void insertionSort(vector<int> &v)
{
    // selects an item from unsorted part of array
    for (int i = 1; i < v.size(); ++i){
        // insert the item @ correct position into sorted part of array
        for (int j = i; j > 0; --j){
            if (v[j] < v[j-1]){
                std::swap(v[j], v[j-1]);
            }
        }
    }
}

int main ()
{
    //vector<int> v{7, 2, 4, 1, 9, 6, 3, 5};
    //vector<int> v{9, -1, -8, 9, 6, -22, 90};
    vector<int> v{4, -6, 2, 2};
    //vector<int> v{1, 2, 3, 4, 5};
    //vector<int> v{5, 4, 3, 2, 1};

    printv(v);
    insertionSort(v);
    printv(v);
}