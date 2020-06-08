#include<iostream>
#include <string>
#include <cctype>
using namespace std;

void printWords(string s)
{
	string word;
	word = s[0];

	int i = 1;

	while (i < s.length())
	{
		if ( isupper(s[i]) ){
			cout << word << endl;
			word = s[i];
		}

		else
			word += s[i];
			++i;
	}

	cout << word;
}

int main() {
	string s;
	cin >> s;
	printWords(s);
	return 0;
}
