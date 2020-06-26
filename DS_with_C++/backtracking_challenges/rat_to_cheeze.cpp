#include<iostream>
using namespace std;


void printBoard(char b[][100], int n, int m)
{
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (b[i][j] == 'A')
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}


bool move(char b[][100], int n, int m, int i = 0, int j = 0)
{
    // blocking conditions
    if (i < 0 or i >= n or j < 0 or j >= m or b[i][j] == 'X' or b[i][j] == 'A')
        return false;

    // Base case: when rat reaches indices (n-1) and (m-1)
    if (i == (n - 1) and j == (m - 1)){
        b[i][j] = 'A';
        printBoard(b, n, m);
        b[i][j] = 'O';
        return true;
    }

    b[i][j] = 'A';
    bool v1 = move(b, n, m, i, j + 1);    // move right
    bool v2 = move(b, n, m, i + 1, j);    // move down
    bool v3 = move(b, n, m, i, j - 1);    // move left
    bool v4 = move(b, n, m, i - 1, j);    // move up
    b[i][j] = 'O';

	return (v1 or v2 or v3 or v4);
}

int main() {
    int n, m;
    cin >> n >> m;

    char b[100][100];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> b[i][j];
        }
    }
    
    bool result = move(b, n, m);
	if (!result)
		cout << "NO PATH FOUND";

	return 0;
}
