#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[][1000], int n)
{
    // Print array
    for( int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


void rotateAntiClock(int a[][1000], int n)
{
    // Reverse the array
    for (int i = 0; i < n; ++i)
            reverse(a[i], a[i] + n);


    // Transpose the array
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if ( i < j )
                swap(a[i][j], a[j][i]);
        }
    }
    
    cout << "Transpose: " << endl;
}


int main()
{
    int n, m;
    int a[1000][1000];

    cin >> n >> m;
    cout << endl;
    
    int val = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j){
            a[i][j] = val;
            cout << a[i][j] << "\t";
            ++val;
        }
        cout << endl;
    }

    cout << endl;

    rotateAntiClock(a, n);

    printArray(a, n);
}
