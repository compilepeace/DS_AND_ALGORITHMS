#include<iostream>
#include <algorithm>
using namespace std;


// Check if 'k' pages can be alloted to 'm' students 
int check(int b[], int n, int m, int k)
{
	long long int pages = 0;

	for(int i = 0; i < n; ++i)
	{
		if (pages + b[i] <= k)
			pages += b[i];

		else{
			pages = b[i];
			--m;
		}
	}

	--m;

	return (m >= 0) ? true: false;
}

// Since, we have to find maximum number of pages that can be
// assigned to students, we create a monotonic space/range of pages,
// i.e. b[] and find an appropriate value using binary search algorithm.
int pagesAllocation(int b[], int n, int m)
{
	int ans = 0;
	int s = b[n - 1];		// Minimum pages a student has to read (start of our monotonic search space)
	int e = 0;				// e will store the maximum pages a student is alloted
	for (int i = 0; i < n; ++i)
		e += b[i];			// end of monotonic search space

	// Check if we can allot 'mid' no. of pages to each student or not ?
	while (s <= e)
	{
		int mid = (s + e) >> 1;
		int status = check(b, n, m, mid);
	
		if (status == true){
			ans = mid;
			e = mid - 1;
		}

		else
			s = mid + 1;
	}

	return ans;
}


int main() {
	
	int t;	
	cin >> t; 		// Test cases
	
	for (int z = 0;  z < t; ++z)
	{
		int n, m;
		cin >> n >> m;
		int b[n];

		// Take books pages as input
		for (int i = 0; i < n; ++i)
			cin >> b[i];

		int appropriate_value = pagesAllocation(b, n, m);
		cout << appropriate_value << endl;
	}

	return 0;
}
