#include<iostream>
#include <string>
using namespace std;

bool sumSubsets(int a[], int i, int n, int sum = 0, string s = "")
{
	if (i == n){	
		if (sum == 0 and s.length() != 0){
			return true;
		}
		return false;
	}

    
	bool val1 = sumSubsets(a, i + 1, n, sum, s);                            // excluding a[i]
	bool val2 = sumSubsets(a, i + 1, n, sum + a[i], s + to_string(a[i]));   // including a[i]

	return (val1 or val2);
}


int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int a[n];

        for (int j = 0; j < n; ++j)
            cin >> a[j];

        bool result = sumSubsets(a, 0, n);
        if (result == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

