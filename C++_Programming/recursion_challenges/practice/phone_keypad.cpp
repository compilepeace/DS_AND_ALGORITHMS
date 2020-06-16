
#include <iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};


void generateNames(char *in, char *out, int i, int j)
{
    if (in[i] == '\0'){
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int d = in[i] - '0';
    
    // since 1 and 2 have NULL strings at keypad
    if (d == 1 or d == 0){
        generateNames(in, out, i+1, j);
    }

    for (int k = 0; keypad[d][k] != '\0'; ++k){
        out[j] = keypad[d][k];
        
        // fill the remaining part
        generateNames(in, out, i + 1, j + 1);
    }
}

int main()
{
   char in[100];
   cin >> in;

   char out[100];
   generateNames(in, out, 0, 0);
}
