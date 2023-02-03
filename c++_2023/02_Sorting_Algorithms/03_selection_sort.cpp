#include <iostream>
#include <vector>
using std::cout;
using std::vector;

#define INT_MAX 0x7fffffff

void printv(const vector<int> &v)
{
    cout << "\n";
    for (auto &x: v)
        cout << x << " ";
    cout << "\n";
}

/*
    Time complexity - O(n^2)
    Repeatedly find the minimum element and insert it in the beginning
    of array.
*/
void selectionSort(vector<int> &v)
{
    // iterate till the second last element (i.e. till v[v.size()-2])
    for (int pos = 0; pos < v.size()-1; ++pos){

        // find index of smallest element 
        int idx_min = pos;               // index of min item in remaining array
        for (int j = pos; j < v.size(); ++j){
            if (v[j] < v[idx_min]){
                idx_min = j;
            }
        }

        // place the minimum item at the beginning of remaining array (i.e. @ pos) 
        std::swap(v[pos], v[idx_min]);
    }
}

int main ()
{
    //vector<int> v{7, 2, 4, 1, 9, 6, 3, 5};
    vector<int> v{9, -1, -8, 9, -22, 6, -22, 90};
    //vector<int> v{4, -6, 2, 2};
    //vector<int> v{1, 2, 3, 4, 5};
    //vector<int> v{5, 4, 3, 2, 1};

    printv(v);
    selectionSort(v);
    printv(v);
}