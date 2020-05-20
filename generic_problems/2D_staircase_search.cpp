#include <iostream>
using namespace std;


// Search 'k' in sorted array 'a' in O(n)
void staircaseSearch(int a[][1000], int n, int m, int k)
{
    for (int i = 0; i < n; ++i){
        for (int j = m - 1; j >= 0; --j){
            
            if (a[i][j] == k){
                cout << "Found at [" << i << ", " << j << "] " << endl;
                return;
            }

            else if (a[i][j] < k){
                cout << "[+] At : " << a[i][j] << endl;
                break;
            }

            cout << "[+] At : " << a[i][j] << endl;
        }
    }
}

int main()
{
    int n, m, k;
    int a[1000][1000];

    cin >> n >> m >> k;
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

    staircaseSearch( a, n, m, k);
}
