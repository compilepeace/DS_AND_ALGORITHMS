#include <iostream>
using namespace std;

char mapping[27] = {0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                    'V', 'W', 'X', 'Y', 'Z'};

void gs(char in[], char out[], int i, int j)
{
    // Base case
    if (in[i] == '\0'){
        out[j] = '\0';
        cout << out << endl;
        return;
    }


    // skip 0 as a case
    if (in[i] == '0'){
        gs(in, out, i + 1, j);
    }

    else{
    
        // One digit at a time
        int d = in[i] - '0';
        out[j] = mapping[d];
        gs(in, out, i + 1, j + 1);
    
        // two digits at a time
        if (in[i+1] != '\0'){
        
            d = d*10 + (in[i+1] - '0');
        
            if ( d <= 26){
                out[j] = mapping[d]; 
                gs(in, out, i + 2, j + 1);
            }
        }

    }
}


int main()
{
    char in[1000];
    cin >> in;

    char out[1000];

    gs(in, out, 0, 0);
}
