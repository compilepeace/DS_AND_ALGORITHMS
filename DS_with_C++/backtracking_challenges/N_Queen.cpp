#include <iostream>
using namespace std;


void printBoard(bool b[][10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j){
            if (b[i][j] == true)
                cout << "Q" << ' ';
            else
                cout << "_" << ' ';
        }
        cout << endl;
    }
    cout << "----------------------\n";
}

bool isSafe(bool b[][10], int n, int i, int j)
{
    int x = 0, y = 0;

    // left diagonal check
    x = i - 1;
    y = j - 1;
    while ( x >= 0 and y >= 0 ){
        if (b[x][y] == true)
            return false;
        --x;
        --y;
    }

    // check for current column
    x = i - 1;
    y = j;
    while (x >= 0){
        if (b[x][y] == true)
            return false;
        --x;
    }

    // right diagonal check
    x = i - 1;
    y = j + 1;
    while ( x >= 0 and y <= n ){
        if (b[x][y] == true)
            return false;
        --x;
        ++y;
    }

    return true;
}


int nQueen(bool b[][10], int n, int i)
{
    // Base case: if we reach end row
    if (i == n){
        printBoard(b, n);
        return 1;
    }
    
    int count = 0;

    // Recursive case : try to place the queen in current row 'i...n-1'
    for (int j = 0; j < n; ++j){

        // Check the column before placing queen
        bool val = isSafe(b, n, i, j);
        if (!val){
            continue;
        }

        b[i][j] = true;
        count += nQueen(b, n, i + 1);        // position count satisfying the N queen problem, goto next row
        b[i][j] = false;
    } 

    return count;
}

int main()
{
    bool board[10][10] = {0};
    int n;

    cin >> n;

    int countPos = nQueen(board, n, 0);
    cout << "There are " << countPos << " no. of positions\n";
}
