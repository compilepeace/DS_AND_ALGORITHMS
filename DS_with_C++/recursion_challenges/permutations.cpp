#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

void findGreater(string s, string s1, int i = 0)
{
	if (s[i] == '\0'){
		// store all the strings lexiographically greater than s1 in vector v1
		if (s > s1)
			v.push_back(s);
		return;
	}

	for (int j = i; j < s.length(); ++j){
		swap(s[i], s[j]);
		findGreater(s, s1, i + 1);
		swap(s[i], s[j]);
	}
}


int main() {
	string s;

	cin >> s;

	findGreater(s, s);
	sort(v.begin(), v.end());

	for (auto str: v)
		cout << str << endl;

	return 0;
}
