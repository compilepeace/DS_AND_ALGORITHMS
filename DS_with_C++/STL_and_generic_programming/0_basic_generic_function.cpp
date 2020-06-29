/*
 * Standard Template Library (STL)
 *
 *  Templates   - gives freedom from underlying datatypes
 *  Iterators   - gives freedom from containers
 *  Comparators - gives freedom from different type of operations happening on the data.
 *
 *
 * We used templates to create generic functions.
 * Iterators are used to parse over any container (array, vector, list, set, map etc.)
 * Comparators are made using 'Functors' or 'Functional objects'
 *
*/



#include <iostream>
#include <list>
using namespace std;

template<class forwardIterator, class T>
forwardIterator linear_search(forwardIterator start, forwardIterator end, T key)
{
    while (start != end){
        
        if (*start == key)
            return start;

        ++start;
    }

    return end;
}


int main()
{
    int a[] = {6, 3, 8, 4, 1, 9};
    int n = sizeof(a)/sizeof(int );

//    cout << linear_search(a, a + n, 1) << endl;
    
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    auto it = linear_search(l.begin(), l.end(), 2);
    if (it != l.end())
        cout << "Found at index: " << it-l.begin() << endl;//it - l.begin() << endl;

    it = linear_search(l.begin(), l.end(), 5);
    if (it != l.end())
        cout << "Found at index: " << *it << endl;//- l.begin() << endl;
    else
        cout << "Not found !\n";
}
