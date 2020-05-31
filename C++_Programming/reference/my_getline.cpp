#include <iostream>
using namespace std;


void myGetline(char a[], int MAX_LEN, char delimiter = '\n')
{
    int i = 0;
    char ch = cin.get();

    for (; ch != delimiter; ch = cin.get())
    {
        if (i == MAX_LEN - 1)
            break;
        a[i] = ch;
        ++i;
    }

    a[i + 1] = '\x00';
}

int main()
{
    int MAX_LEN = 1000;
    char a[MAX_LEN] = {0};
    myGetline(a, MAX_LEN, '$');
    
    cout << a << endl; 

return 0;
}
