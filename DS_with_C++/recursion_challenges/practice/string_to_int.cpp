#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int stringToInt(char *s, int n)
{
    // Base case
    if (n == 0)
        return 0;

    int v = stringToInt(s + 1, n - 1);
    return (v + (s[0] - '0') * pow(10, n - 1));
}


int toInt(char *s, int n)
{
    if (n == 0)
        return 0;

    int digit = s[n - 1] - '0';
    int smallAns = toInt(s, n - 1);
    return (smallAns * 10) + digit;
}

int main()
{
    char a[] = {'0', '0', '1', '2', '3', '4'};

    //int n = stringToInt(a, strlen(a));
    
    int n = toInt(a, strlen(a));
    printf("%d\n", n);
}
