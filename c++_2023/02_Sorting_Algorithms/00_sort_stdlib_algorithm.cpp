#include <iostream>
#include <algorithm>
#include <vector>

using std::cerr;
using std::vector;

void printV(const vector<int> &v);
void printA(const int a[], int n);

/*
    defines callback function used by std::sort()
*/
bool comparator(int a, int b){
    return a > b;   // descending order
}

/*
    This program uses <algorithm>
    - std::reverse()
    - std::sort()
    NOTE: <algorithm> functions will use [start, end) - notice the open bracket at end !
*/
int main()
{
    int a[] = {9, -1, -8, 9, -22, 6, -22, 90, 7};
    int sz = sizeof(a)/sizeof(int);

    vector<int> v{9, -1, -8, 9, -22, 6, -22, 90};

    printA(a, sz);
    //std::sort(a, a+sz);                       // sort entire array in ascending order
    //std::sort(a, a+sz, comparator);           // sort entire array using comparator (callback)
    //std::sort(a, a+sz, std::greater<int>());  // used in-built templatized comparator
    std::sort(a, a+sz, [](int a, int b){
        return a > b;
    }); // implemented comparator function as lambda expression (anonymous function)
    printA(a, sz);

    printV(v);
    //std::sort (v.begin(), v.end());             // sorts in ascending order
    //std::reverse (v.begin(), v.end());          // reverses the container
    std::sort (v.begin(), v.end(), [](int a, int b){
        return (a > b);     // descending order
    });
    printV(v);
}

// print vector
void printV(const vector<int> &v)
{
    cerr << "\nVector - ";
    for (auto &x: v)
        cerr << x << " ";
    cerr << "\n";
}

// print array
void printA(const int a[], int n)
{
    cerr << "\nArray - ";
    for (int i = 0; i < n; ++i){
        cerr << a[i] << " ";
    }
    cerr << "\n";
}