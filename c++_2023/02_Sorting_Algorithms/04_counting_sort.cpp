#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::vector;

void printv(const vector<int> &v)
{
    cout << "\n";
    for (auto &x: v)
        cout << x << " ";
    cout << "\n";
}

/*
    Time complexity - O(range + n) : [linear time complexity]
    range is the maximum int value present inside input array.
    steps for counting sort algo are -
        - create a counting array of size == range+1.
        - parsing input array, use each encountered item as index
          into counting array and increment the value at that index
        - populate input array using counting array.

    NOTE: can sort only array of positive integers (occuring in some range)
*/
void countingSort(vector<int> &v)
{
    // getting maximum element in input vector via <algorithm>
    int vsize = *std::max_element(v.begin(), v.end());

    // created counting vector
    vector<int> counting(vsize+1, 0);
    for (const auto &x: v){
        if (x < 0){
            cerr << "Negative int encountered, counting sort cannot proceed."
                 << "Try supplying an input array consisting of positive numbers."
                 << "Aborting now!\n";
            return;
        }
        counting[x] += 1;
    }

    // parsed counting vector
    int j = 0;
    for (int i = 0; i < counting.size(); ++i){
        while (counting[i] > 0){
            v[j++] = i; 
            --counting[i];
        }
    }
}

int main ()
{
    //vector<int> v{7, 2, 4, 1, 9, 2, 2, 3, 6, 3, 5};
    //vector<int> v{9, -1, -8, 9, 6, -22, 90};
    vector<int> v{4, -6, 2, 2};
    //vector<int> v{1, 2, 3, 4, 5};
    //vector<int> v{5, 4, 3, 2, 1};

    printv(v);
    countingSort(v);
    printv(v);
}