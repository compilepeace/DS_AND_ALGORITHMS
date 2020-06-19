#include <iostream>
using namespace std;


// co : count_of_opening_brackets
// cc : count_of_closed_brackets
// o  : output array
// n  : input 
// i  : index tracking current location (to put brackets on)
// function prints all possible balanced opening brackets
void printB(char o[], int n, int co, int cc, int i)
{
    if (i == 2*n){
        o[i] = '\0';
        cout << o << endl;
        return;
    }


    // If we want to put an opening bracket
    if (co < n){
        o[i] = '(';
        printB(o, n, co + 1, cc, i + 1);
    }

    if (cc < co){
        o[i] = ')';
        printB(o, n, co, cc + 1, i + 1);
    }
}



int main()
{
    int n;
    cin >> n;

    char *out = new char[2*n];

    printB(out, n, 0, 0, 0);
}
