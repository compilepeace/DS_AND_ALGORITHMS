#include<iostream>
#include <cmath>
using namespace std;

void printBoard(int b[][9], int n)
{
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
}

bool canPlace(int b[][9], int n, int i, int j, int num)
{
	int si, sj, rn;

	rn = sqrt(n);
	si = (i/rn) * rn;
	sj = (j/rn) * rn;

	for (int x = si; x < (si + rn); ++x){
		for (int y = sj; y < (sj + rn); ++y){
			if (b[x][y] == num)
				return false;
		}
	}

	for (int x = 0; x < n; ++x){
		if (b[i][x] == num || b[x][j] == num)
			return false;
	}

	return true;
}

bool sudokuSolver(int b[][9], int n, int i, int j)
{
	// Base case : If i reaches one past the end of board
	if (i == n){
		printBoard(b, n);
		return true;
	}

	// shift to the next row if 'j' has reached one past the end of board
	if (j == n)
		return sudokuSolver(b, n, i + 1, 0);

	// check if the current cell already contains a number
	if (b[i][j] != 0)
		return sudokuSolver(b, n, i, j + 1);

	// If current cell is vacant (to be filled), choose the numbers between [1..n]
	for (int num = 1; num <= n; ++num)
	{
		if (canPlace(b, n, i, j, num)){
			b[i][j] = num;
			bool solved = sudokuSolver(b, n, i, j + 1);
			if (solved == true){
				return true;
			}
		}
	}

	b[i][j] = 0;
	return false;
}

int main() {
	int n;
	cin  >> n;

	int b[9][9] = {0};

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> b[i][j];
		}
	}

    cout << "----------------------------------------\n\n";

	sudokuSolver(b, n, 0, 0);

	return 0;
}
