#include<iostream>
#include <string>
#include <set>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

// print all the names which contains the substring specified by 'o'
void printNames(string o, set<string> &names)
{
	for (auto str: searchIn){
		size_t found = str.find(o);
		if (found != string::npos){
			names.insert(str);
		}
	}
}


void keypad(string s, int i, string o, set<string> &names)
{
	if (s[i] == '\0'){
		printNames(o, names);
		return;
	}

	int n = s[i] - '0';
	string str = table[n];

	for (int k = 0; k < str.length(); ++k){
		keypad(s, i + 1, o + str[k], names);
	}

}

int main() {
	string s, o;
	cin >> s;

	set<string> names;

	keypad(s, 0, o, names);
	
	for (auto e: names){
		cout << e << endl;
	}
	
	return 0;
}
