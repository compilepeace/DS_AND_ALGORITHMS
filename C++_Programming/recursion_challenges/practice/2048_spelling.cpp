#include <iostream>
using namespace std;


void printSpelling(int n)
{
    if (n == 0)
        return;

    int digit = n % 10;
    printSpelling( n/10 );

    switch(digit)
    {
        case 1: cout << "one ";
                break;
        case 2: cout << "two ";
                break;
        case 3: cout << "three ";
                break;
        case 4: cout << "four ";
                break;
        case 5: cout << "five ";
                break;
        case 6: cout << "six ";
                break;
        case 7: cout << "seven ";
                break;
        case 8: cout << "eight ";
                break;
        case 9: cout << "nine ";
                break;
        case 0: cout << "zero ";
                break;
        default: cout << "Default\n";
                break;
    }
}

int main()
{
    int n;
    cin >> n;

    printSpelling(n);
    cout << "\nn: " << n <<endl;
}
