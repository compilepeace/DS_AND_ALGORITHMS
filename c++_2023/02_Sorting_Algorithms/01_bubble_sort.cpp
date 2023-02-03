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
    time complexity - O(n^2)
    When the water boils, bigger bubbles float towards the surface
    while the smaller bubbles stay at the bottom. Bubble sort is
    based on this concept.
    eg: [4, -6, 2, 2]
    ->  [-6, 2, 2, 4]

    NOTE: This algorithm is sorted for best-case scenario, i.e. when 
          a list is already sorted using swap_flag.
*/
void bubbleSort(vector<int> &v)
{
    bool swap_flag = false;     // optimized for best case scenario - O(n)

    for (int i = v.size()-2; i >= 0; --i){
        for (int j = 0; j <= i; ++j){
            if (v[j] > v[j+1]){
                std::swap(v[j], v[j+1]);
                swap_flag = true;           // if swapping occured at least once
            }
        }
        if (!swap_flag){
            cout << "List already sorted";
            return;
        }
        cout << "A bubble got sorted\n";
    }
}

int main ()
{
    //vector<int> v{7, 2, 4, 1, 9, 6, 3, 5};
    //vector<int> v{9, -1, -8, 9, 6, -22, 90};
    //vector<int> v{4, -6, 2, 2};
    vector<int> v{1, 2, 3, 4, 5};
    //vector<int> v{5, 4, 3, 2, 1};

    printv(v);
    bubbleSort(v);
    printv(v);
}