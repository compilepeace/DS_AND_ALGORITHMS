#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	int i = 0;
	while (s1[i] == s2[i]) ++i;

	if (s1[i] == ')')
		return true;
	else
		return false;
}

void parantheses(string o, int n, vector<string> &v, int oc = 0, int cc = 0)
{
	if (oc == n and cc == n){
		v.push_back(o);
		return;
	}

	// placing an open parantheses
	if (oc < n){
		parantheses(o + '(', n, v, oc + 1, cc);
	}

	if (cc < oc){
		parantheses(o + ')', n, v, oc, cc + 1);
	}
}

int main() {
	int n;
	string o;
	vector<string> v;
	cin >> n;

	parantheses(o, n, v);

	sort(v.begin(), v.end(), compare);

	for (auto str: v)
		cout << str.c_str() << endl;

	return 0;
}
