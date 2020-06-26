#include<iostream>
using namespace std;

int val;

// The aim of this function is take all posible routes and store the count of maximum
// number of cells that can be reached from a path in 'val'.
void markPos(int a[][1000], int n, int i = 0, int j = 0, int count = 0)
{
	// blocking conditions
	if (i < 0 or j < 0 or i >= n or j >= n or a[i][j] == 0)
		return;

	val = max(val, count + 1);
	a[i][j] = 0;			// Mark as visited
	markPos(a, n, i - 1, j + 2, count + 1);
	markPos(a, n, i - 1, j - 2, count + 1);
	markPos(a, n, i + 1, j + 2, count + 1);
	markPos(a, n, i + 1, j - 2, count + 1);
	markPos(a, n, i + 2, j - 1, count + 1);
	markPos(a, n, i - 2, j - 1, count + 1);
	markPos(a, n, i + 2, j + 1, count + 1);
	markPos(a, n, i - 2, j + 1, count + 1);
	a[i][j] = 1;			// Mark as not visited
}

int main() {
	int n, valid_cells;
	cin >> n;
	int a[1000][1000];


	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
			if (a[i][j] == 1)
				++valid_cells;		// counts the total number of cells on which knight can land
		}
	}

	val = 0;	            		// val is count of max_reachable cells by any route
	markPos(a, n);

	cout << valid_cells - val;  	// min_unreachable_cells = valid_cells - count_max_reachable_cells (through any path)

	return 0;
}
