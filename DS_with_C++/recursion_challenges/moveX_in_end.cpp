#include<iostream>
#include <string>
using namespace std;

void moveX(string &s, int i = 0, int k = 1)
{
	if (i >= s.length() - k)
		return;

	// If something other than 'x' is encountered
	if (s[i] != 'x')
		moveX(s, i + 1, k);
	
	// If an 'x' is encountered
	else{
		int j;
		// move 'x' to last, 'k' represents the place reserved
		// for 'x' from the last index.
		for (j = i; j < (s.length() - k) ; ++j){
			s[j] = s[j + 1];
		}
		s[j] = 'x';
		moveX(s, i, k + 1);
	}
}

int main() {
	string s;
	cin >> s;

	moveX(s);
	cout << s << endl;

	return 0;
}
