#include<iostream>
#include <string>
using namespace std;

void printPosibilities(string s, int i, string o = "")
{
	if (i >= s.length()){
		cout << o << endl;
		return;
	}

	int d1 = s[i] - '0';
	int d2 = s[i + 1] - '0';
	char letter1 = d1 + 'A' - 1;		// letter by including s[i]

	printPosibilities(s, i + 1, o + letter1);
	
	int num = (d1 * 10) + d2;
	if (num > 0 and num <= 26){
		char letter2 = num + 'A' - 1;	// letter by including s[i]*10 + s[i + 1]
		printPosibilities(s, i + 2, o + letter2);
	}
}

int main() {

	string s;
	cin >> s;

	printPosibilities(s, 0);

	return 0;
}
