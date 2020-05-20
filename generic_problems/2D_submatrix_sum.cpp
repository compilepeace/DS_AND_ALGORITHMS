#include <iostream>
using namespace std;


int sumSubmatrices(int a[][1000], int n, int m)
{
    long long tl = 0, br = 0, sum = 0;
    int occurence; 

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m ; ++j)
        {
            tl = (i + 1) * (j + 1);
            br = (n - i) * (m - j);
            occurence = tl * br;            // no. of occurence of a[i][j] in all submatrices
            sum += a[i][j] * occurence;
        }
    }

    return sum;
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
        {
            a[i][j] = 1;
        }
    }

    int result = sumSubmatrices(a, n, m);
    cout << "Sum of all the submatrices of the given matrix: " << result << endl;
}
