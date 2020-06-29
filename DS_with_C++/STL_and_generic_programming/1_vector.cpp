#include <iostream>
#include <vector>
using namespace std;


/* METHODS

 v.reserve(1000)    - to avoid doubling (a costly operation), we reserve the size of vector before
                      we start using it.

 v.push_back(x)     - adds an element 'x' to the end of the vector O(1)
 v.pop_back()       - removes the last element O(1) 
 v.insert(it, x)    - inserts value 'x' at the location specified by the iterator 'it' O(n)
 v.insert(it, n, x) - insert 'n' elements having value 'x' at location specified by 'it' O(n)
 v.front()          - to get the first element of the vector
 v.back()           - to get the last element of the vector.
 
 v.erase(it)        - removes the element specified by 'it' from the vector.
 v.erase(it1, it2)  - removes all the elements from 'it1' to 'it2'
 v.resize(n)        - increases the vector size by n elements. 
 v.clear()          - removes all the elements from the vector (capacity remains the same)
 v.empty()          - returns true if the size() is 0

 v.size()      - returns the size of the vector
 v.capacity()  - returns the size of the underlying vector
 v.max_size()  - returns the maximum size the OS allows the vector to have
*/




template<typename T>
void print(vector<T> &v)
{
     for (auto x: v)
        cout << x << " ";
        cout << endl;
}


int main()
{
    // (4) Ways to initialize a vector
    vector<int> a;
    vector<int> b(20, 7);               // A vector with 20 elements, each initilized to a value of 7
    vector<int> c(b.begin(), b.end());  // 'c' is a copy of vector 'b'
    vector<int> d{1,2,3,4,5,6};

  
    // (3) Ways to iterate over a vector
    for (int i = 0; i < d.size(); ++i){
        cout << d[i] << " ";
    }
    cout << endl;

    for (auto it = d.begin(); it != d.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    for (auto x: d){
        cout << x << " ";
    }
    cout << endl;


    // Ways of taking input
    for (int i = 0; i < 3; ++i){
        int n;
        cin >> n;
        a.push_back(n);
    }

    print(a);
}
