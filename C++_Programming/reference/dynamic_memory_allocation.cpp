#include <iostream>
using namespace std;


// To dynamically allocate a 2D array
int main()
{
    
    int rows = 3, cols = 3;


//---------------------------------------------------------------------------------------
    // Allocate 'array of pointers' on heap (zero/NULL initialized values)
    int **a = new int *[rows]{0};
    
    // Allocate space for each array(row) and store row addresses inside array of pointers 
    for (int i = 0; i < rows; ++i)
        a[i] = new int[cols]{0};        // Zero initialized
//---------------------------------------------------------------------------------------


    // Input value inside 2D array we just created on heap
    int value = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j){
            a[i][j] = value;
            ++value;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    delete [] a;
}
