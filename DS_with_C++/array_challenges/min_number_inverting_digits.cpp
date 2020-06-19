#include<iostream>
#include <string>
using namespace std;


// Invert digit x by => (9 - x) only if (9-x) < x and
// Since the number should not start with '0', therefore
// if s[0] == '9', do not invert it!
string minNumber(string s)
{
	string result;

	for (int i = 0; i < s.size(); ++i)
	{
		int n1 = s[i] - 48;
		int n2 = 9 - n1;
	
		if (i == 0 and s[i] == '9')
			result += '9';
		else
			result += to_string( min(n1, n2) );
	}
	return result;
}

int main() {
	string s, result;

	cin >> s;

	result = minNumber(s);
	cout << result;
	
	return 0;
}
