#include<iostream>
#include <string>
using namespace std;


int convertToInt(string s, int i = 0, int num = 0)
{
	if (s[i] == '\0'){
		return num;
	}

	int d = s[i] -  '0';
	int val = num * 10 + d;
	return convertToInt(s, i + 1, val);
}


int main() {
	string s;
	cin >> s;

	cout << convertToInt(s);	

	return 0;
}
