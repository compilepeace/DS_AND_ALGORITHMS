#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;               // lexiographic comparison

    // compare on basis of length
    return a.length() < b.length();
}

int main()
{
    string a[20];
    int n;

    cin >> n;
    
    // Discarding '\n'
    cin.get();
    
    for (int i = 0; i < n; ++i)
    {
        getline(cin, a[i]);
    }

    sort(a, a+n, compare);

    for (auto s: a) cout << s << endl;
}
