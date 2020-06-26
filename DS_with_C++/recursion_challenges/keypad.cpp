#include<iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void keypad(string s, int i, string o)
{
	if (s[i] == '\0'){
		cout << o << endl;
		return;
	}

	int n = s[i] - '0';
	string str1 = table[n];

	for (int k = 0; k < str1.length(); ++k){
		keypad(s, i + 1, o + str1[k]);
	}


}

int main() {
	string s;
	cin >> s;

	string o;

	keypad(s, 0, o);
	return 0;
}
