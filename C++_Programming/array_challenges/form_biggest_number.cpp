#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Compare for eg: 98 and 9 => 998 or 989
bool compare(string a , string b)
{
	string ab = a.append(b);
	string ba = b.append(a);

	// Both 'ab' and 'ba' strings having equal no. of characters are forced to 
	// get compared on the basis of their lexical values.
	// compare() method returns a value > 0 : if the length of 'ab' is greater than 'ba',
	// if length is same, it compares lexical of 'ab' and 'ba'.
	// Returns a value < 0 : if 'ab' < 'ba' (lexiographic comparison)
	return ab.compare(ba) > 0 ? true: false;
}

int main() {

	int t, n;
	cin >> t;
	cin.get();

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vector<string> v;
		string result;

	
		for (int i = 0; i < n; ++i)
		{
			string temp;
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < n; ++i)
			result += v[i];
		
		cout << result << endl;

	}

	return 0;
}
