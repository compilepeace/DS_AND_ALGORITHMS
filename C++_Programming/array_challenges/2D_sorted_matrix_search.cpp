#include<iostream>
using namespace std;

// Since the 2D array is sorted, it takes O(n) to find an element in it
int findK(int a[][1000], int n, int m, int k)
{
	int i = 0;
	int j = m - 1;

	for (int i = 0; i < n; ++i){
		for (int j = m - 1; j >= 0; --j)
		{
			if (k == a[i][j])
				return 1;

			else if (k > a[i][j])
				break;
		}
	}
	return 0;
}

int main() {
	int n, m;
	int a[1000][1000];

	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}

	int k;
	cin >> k;

	int result = findK(a, n, m, k);
	cout << result;

	return 0;
}
