#include<iostream>
#include <string>
#include <set>

using namespace std;

// Generates and stores permutations of string ip in set s
void permute(string ip, int i, set<string> &s)
{
	// Base case: when we reach the end of input string
	if (ip[i] == '\0'){
		s.insert(ip);
		return;
	}

	for (int j = i; j < ip.length(); ++j){
		swap(ip[i], ip[j]);
		permute(ip, i + 1, s);
		swap(ip[i], ip[j]);                 // Backtrack to maintain the original string
	}
}


int main() {
	string input;
	set<string> s;

	cin >> input;

	permute(input, 0, s);

	for (auto p: s)
		cout << p << endl;

	return 0;
}
