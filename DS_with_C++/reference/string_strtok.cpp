#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// Vectorise a string
int main()
{
    char s[1000] = "This is Abhinav";
    vector<string> result;
    char *ptr;

    // cin.getline() doesn't work with strings
    //getline(cin, s);

    ptr = strtok( s, " ");
    while ( ptr != NULL)
    {
        string temp(ptr);
        result.push_back(temp);

        ptr = strtok( NULL, " ");        // strtok(string, delimiter)
    }

    for (auto str: result) cout << str << endl;
}
