#include <iostream>
#include <climits>
using namespace std;

int maxSubmatrixSum(int a[][1000], int n, int m)
{
   // add row wise from the bottom
   for (int i = n - 1; i >= 0; --i)
   {
       for (int j = m - 2; j >= 0; --j)
           a[i][j] += a[i][j+1];
   }

   // add colum wise from the bottom
   for (int j = m - 1; j >= 0; --j)
   {
       for (int i = n - 2; i >= 0; --i)
           a[i][j] += a[i+1][j];
   }

   int result = INT_MIN; 
   // Find the largest number from the matrix 
   for (int i = 0; i < n; ++i)
   {
       for (int j = 0; j < m; ++j)
            result = max(result, a[i][j]);
   }

   return result;
}


int main()
{
    int a[1000][1000];
    int n, m;

    cout << "Enter the dimensions of the matrix: ";
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    int result = maxSubmatrixSum(a, n, m);
    cout << "Maximum submatrix sum : " << result << endl;
}
