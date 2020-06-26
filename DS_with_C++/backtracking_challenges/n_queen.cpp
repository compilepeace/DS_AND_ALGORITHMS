#include<iostream>
using namespace std;

bool canPlace(bool b[][12], int n, int i, int j)
{
	int x = i;
	int y = j;
	// check left diagonal
	while (x >= 0 and y >= 0){
		if (b[x--][y--] == true)
			return false;
	}

	x = i;
	// check the column
	while (x >= 0){
		if (b[x--][j] == 1)
			return false;
	}

	x = i;
	y = j;
	// check right diagonal
	while (x >= 0 and y < n){
		if (b[x--][y++] == true)
			return false;
	}

	return true;
}

int findPos(bool b[][12], int n, int i = 0)
{
	if (i == n){
		return 1;
	}

	int count = 0;

	for (int j = 0; j < n; ++j){
		if (canPlace(b, n, i, j)){
			b[i][j] = 1;
			count += findPos(b, n, i + 1);
			b[i][j] = 0;
		}
	}

	return count;
}

int main() {
	bool b[12][12] = {0};
	int n;
	cin >> n;

	int ans = findPos(b, n);
	cout << ans << endl;

	return 0;
}
