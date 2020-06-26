#include<iostream>
using namespace std;


int printSubsequences(string a, int i, string o)
{
	if (a[i] == '\0'){
		cout << o << " ";
		return 1;
	}

	int c1 = printSubsequences(a, i + 1, o + a[i]);
	int c2 = printSubsequences(a, i + 1, o);

	return (c1 + c2);
}


int main() {
	string s, o;

	cin >> s;
	int result = printSubsequences(s, 0, o);
	cout << endl << "There are " << result << " subsequences in : " << s << endl;

	return 0;
}
