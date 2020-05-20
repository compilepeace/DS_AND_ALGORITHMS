#include <iostream>
#include <cstring>
using namespace std;


void removeDuplicates(char a[])
{
    if (strlen(a) <= 1)
        return;

    int i = 0;

    for (int j = 1 ; j < strlen(a); ++j)
    {
        if (a[i] != a[j])
        {
            ++i;
            a[i] = a[j];
        }
    }

    a[i + 1] = '\0';
}


int main()
{
    char a[1000];

    cin.getline(a, 1000, '\n');

    removeDuplicates(a);
    cout << a << endl;
}
