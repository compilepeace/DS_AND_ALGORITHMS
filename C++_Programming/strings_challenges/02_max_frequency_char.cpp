#include<iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

unsigned char mostFrequentChar(string s)
{
	map<char, int> m;
	int max_count = 0;
	unsigned char result;

	for (auto chr: s)
	{
		++m[chr];
		if (max_count < m[chr])
		{
			max_count = m[chr];
			result = chr;
		}
	}

	return result;
}

int main() {

	string s;

	getline(cin, s);

	unsigned char c = mostFrequentChar(s);
	cout << c;

	return 0;
}
