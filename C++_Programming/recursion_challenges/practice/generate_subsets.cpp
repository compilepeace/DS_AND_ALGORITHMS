// Generate subsets (in the form of subsequences)

#include <iostream>
using namespace std;


int printSubsets(char in[], char out[], int i, int j)
{
    if ( in[i] == '\0' ){
        out[j] = '\0';          // Terminate out string too
        cout << out << " ";
        return 1;
    }

    int x = printSubsets(in, out, i + 1, j);            // Exclusing in[i] into subset
    out[j] = in[i];                                      
    int y = printSubsets(in, out, i + 1, j + 1);        // Including/considering in[i] into subset.

    return (x + y);
}   


int main()
{
    char in[] = {'a', 'b', 'c', '\0'};
    char *out = new char [10000]{0};

    int result = printSubsets(in, out, 0, 0);
    cout << "\n" << in << " had subsets: " << result << endl;
}
