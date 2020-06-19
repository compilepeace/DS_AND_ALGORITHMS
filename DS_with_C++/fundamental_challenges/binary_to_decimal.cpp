#include <iostream>
#include <string>
using namespace std;


long long binaryToDecimal(string b)
{
    long long result = 0;

    for (auto c: b){
        
        result = result << 1;
        if (c == '1')
            ++result;
    }

    return result;
}


int main()
{
    string b;

    cout << "Enter a binary number: ";
    getline(cin, b);

    long long result = binaryToDecimal(b);
    cout << result << endl;
}
