#include <iostream>
using namespace std;


int storeOcc(int *a, int i, int n, int k, int *out, int j)
{
    // base case 
    if (i == n)
        return j;

    // body
    if (a[i] == k){
        out[j] = i;
        return storeOcc(a, i + 1, n, k, out, ++j);
        //out[j + 1] = -1;
    }
    
    return storeOcc(a, i + 1, n, k, out, j);
}


void printAllOcc(int a[], int i, int n, int k)
{
    // Base case
    if (i == n)
        return;
    
    if (a[i] == k)
        cout << a[i] << " ";

    printAllOcc(a, i + 1, n, k);
}

int lastOccurence(int a[], int n, int k)
{
    // Base case
    if (n == 0)
        return -1;

    int i = lastOccurence(a + 1, n - 1, k);
    
    // key not found yet, check for a[0]
    if ( i == -1 ){
        if ( a[0] == k )
            return 0;
        else
            return -1;
    }
    else
        return 1 + i;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 7, 12, 4, 7};
    int size = sizeof(a)/sizeof(int);
    int key;

    cin >> key;

    int i = lastOccurence(a, size, key);

    if (i == -1)
       cout << key << " : index not found\n";
    else
       cout << "index of " << key << " is: " << i << endl;

    int out[size + 1];
    for (int i = 0; i < size + 1; ++i)
        out[i] = -1;

    printAllOcc(a, 0, size, key);
    cout << endl;
 
    int sz = storeOcc(a, 0, size, key, out, 0);

    for (int i = 0; i < sz; ++i)
    {    
        cout << out[i] << " ";
        if (out[i] == -1)
           break;
    }
}

