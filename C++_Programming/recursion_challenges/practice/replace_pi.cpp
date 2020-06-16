#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


#define MY_STRING "apibpicpidddddpie"


void shift2places(char *s, int n)
{
   for (int i = n - 1; i >= 0; --i)
       s[i + 2] = s[i];
}

// Replace "apibcpiee" --> "a3.14bc3.14ee"
void replacePi(char *s, int n)
{
    // base case: if length of string is 0;
    if (n == 0)
        return;

    // If we encounter consecutive 'p' and 'i'
    if (s[0] == 'p' and s[1] == 'i'){
        shift2places(s, n);
        
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
        
        replacePi(s + 4, n - 2);
    }   
    else{
        replacePi(s + 1, n - 1);
    }
}

int main()
{
    char *s = (char *)malloc(10000);
    strncpy(s, MY_STRING, strlen(MY_STRING));

    replacePi(s, strlen(s));
    cout << s << endl;
}
