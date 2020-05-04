#include <iostream>
#include <climits>

using namespace std;


int main()
{
	int min_so_far = INT_MAX;
	int max_so_far = INT_MIN;
	int n;

	while (cin >> n && n != -1) {
		if (n < min_so_far) min_so_far = n;
		if (n > max_so_far) max_so_far = n;
	}

	cout << "Min: " << min_so_far << endl;
	cout << "Max: " << max_so_far << endl; 
}
