/*
=>  Sort all the strings ( lexicographically ) but if a string is 
    present completely as a prefix in another string, then string 
    with longer length should come first

Sample Input
    3
    bat
    apple
    batman

Sample Output
    apple
    batman
    bat
*/


#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// [bat, apple, batman] is sorted as
// [apple, batman, bat]
bool compare(string s1, string s2)
{
	bool IS_PREFIX = true;

	for (int i = 0; i < min(s1.length(), s2.length()); ++i)
	{
		if (s1[i] != s2[i])
			IS_PREFIX = false;
	}

	// If a string is prefix of other
	if (IS_PREFIX)
		return (s1 > s2) ? 1: 0;
	else
		return (s1 < s2) ? 1: 0;
}


int main() {
	vector<string> v;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (auto i: v)
		cout << i << endl;

	return 0;
}
