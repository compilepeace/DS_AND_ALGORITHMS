#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}


void isLarger(int a[], int n, bool (&func)(int , int ) )
{
   for (int i = 0; i < n; ++i)
   {
       for (int j = 0; j < n - i - 1; ++j)
       {
            if ( func(a[j], a[j+1]) )
                swap(a[j], a[j+1]);
       }
   }
}


int main()
{
/*    int a[10];
    for (int i = 0; i < 10; ++i)
        a[i] = i;

    isLarger(a, 10, cmp);

    for (int i = 0; i < 10; ++i)
        cout << a[i] << ", ";
        cout << endl;
*/

vector< int > data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
auto lower = std::lower_bound(data.begin(), data.end(), 4);
auto upper = std::upper_bound(data.begin(), data.end(), 4);

cout << *lower << ": " << *upper << endl;
for(auto it = lower; it != upper; it++)
cout << *it << ' ';
}

