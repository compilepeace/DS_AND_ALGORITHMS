#include<iostream>
#include <algorithm>
using namespace std;


bool check(int b[], int n, int k, int mid)
{
	long long int tsf = 0;		// Time so far
	
	int i = 0;
	while (i < n){

		if ( (tsf + b[i]) > mid ){
			tsf = b[i];
			--k;
		}
		else
			tsf += b[i];
		++i;
	}
	--k;
	
	return (k >= 0) ? true: false;
}

// Returns the minimum time required by 'k' painters to print 'n' boards of 'b[i]' units of board
// where time taken to paint 1 unit of board is 't' units.
long long int getMinTime(int b[], int n, int k)
{
	long long int s, mid, e = 0, result = -1;

	s = b[n - 1];	// least time required in our monotonic space (range)
    for (int i = 0; i < n; ++i)
        e += b[i];  // max time required is when a single painter has to paint all the boards

	while (s <= e)
	{
		mid = (s + e) >> 1;
		bool status = check(b, n, k, mid); 		// Check if it is possible to paint n boards by k painters in 'mid' units of time ?
		
		if (status == true){
			result = mid;
			e = mid - 1;
		}
			
		else
			s = mid + 1;
	}

	return result;
}	

int main() {

	int n, k, t;

	cin >> n >> k >> t;
	int b[n];

	for (int i = 0; i < n; ++i)
	{
        int unit;
        cin >> unit;
        b[i] = unit * t;
    }

	long long int result = getMinTime(b, n, k);
	cout << (result % 10000003);

	return 0;
}
