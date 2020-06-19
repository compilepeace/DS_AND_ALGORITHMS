#include <iostream>
using namespace std;


void printPath(int ans[][10], int m, int n)
{
    for (int i = 0; i <= m; ++i){
        for (int j = 0; j <= n; ++j)
            cout << ans[i][j] << " ";
            cout << endl;
    }
        cout << "----------------------" << endl;
}


int ratInMaze(char maze[][10], int ans[][10], int m, int n, int i, int j)
{
    if ( i == m and j == n ){
        ans[i][j] = 1;
        printPath(ans, m, n);
        return 1;
    }

    int countRightPaths = 0;
    int countLeftPaths = 0;

    // Is rat inside the grid ? return false if not !
    if (maze[i][j] == 'X' or i > m or j > n ) 
        return 0;

    ans[i][j] = 1;          // Welcome
    countRightPaths += ratInMaze(maze, ans, m, n, i, j + 1);       // move right
    countLeftPaths  += ratInMaze(maze, ans, m, n, i + 1, j);       // move down
    ans[i][j] = 0;          // departure

    return (countRightPaths + countLeftPaths);
}


int main()
{
    char maze[10][10] = {
                            "0000",
                            "00X0",
                            "000X",
                            "0X00" 
     };

     int ans[10][10] = {0};
    
     int count = ratInMaze(maze, ans, 3, 3, 0, 0);
     if (count)
        cout << count << " paths found !\n";
     else
        cout << "No path found to the end\n";

     return 0;
}
