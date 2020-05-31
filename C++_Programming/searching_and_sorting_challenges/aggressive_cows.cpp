#include <iostream>
#include <algorithm>
using namespace std;


// Check if we can place 'count' cows at a distance 'dist' on position 'pos' array.
bool canPlaceCows(int pos[], int n, int count, int dist)
{
    int last_placed = pos[0];

    for (int i = 1; i < n; ++i)
    {
       if (pos[i] - last_placed >= dist){
           --count;
           last_placed = pos[i];
       }
    }
	--count;

    return (count > 0) ? false: true;
}


int main()
{
	int n, cows_count;
	cin >> n >> cows_count;

	int pos[n];
	for (int i = 0; i < n; ++i)
		cin >> pos[i];

    // We have to find an appropriate distance for each cow to be placed on position array.
    // distance should be maximum such that all cows can be placed on positions.

    sort(pos, pos + n);

    // We will try placing the cows at a distance we choose from our own search space 
    int ans = 0;
    int s = 0;
    int e = pos[n-1];

    while (s <= e)
    {
        int mid = (s + e) >> 1;
        
        bool status = canPlaceCows(pos, n, cows_count, mid);
        
        if (status){
            ans = mid;
            s = mid + 1;
        }
        
        else 
            e = mid - 1;
    }

    cout << ans 
         << endl;

}

