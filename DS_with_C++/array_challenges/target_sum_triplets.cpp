#include<iostream>
#include <algorithm>
using namespace std;


// Print the triplets which sum to k
void printTriplets(int *a, int n, int k)
{
    int result = 0, start, end;

    // sort the array
    sort(a, a + n);

    // Iterate over the array
    for (int i = 0; i < n; ++i)
    {
        result = a[i];
        start = i + 1;
        end = n - 1;
        // Find a pair which sums to k
        while (start < end)
        {
            int sum = result + a[start] + a[end];

            if (sum == k){
                cout << result << ", " << a[start] << " and " << a[end] << endl;
                ++start;
                --end;
            }
            else if ( sum > k)
                --end;
            else
                ++start;
        }
    }
}

int main() {

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int k;
    cin >> k;

    if (n >= 3)
        printTriplets(a, n, k);

    return 0;
}

