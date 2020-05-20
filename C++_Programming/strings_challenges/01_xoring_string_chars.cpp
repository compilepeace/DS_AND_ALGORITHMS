#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	
	int t; 		// No. of test cases
	cin >> t;
	
	cin.get();	// Discarding '\n' char after above input

	for (int i = 0; i < t; ++i)
	{	
		// Take a pair as input
		string s1, s2;
		getline(cin, s1, ' ');
		getline(cin, s2);
	
		for (int j = 0; j < s1.size(); ++j)
			cout << ((s1[j] - 48) ^ (s2[j] - 48));
		cout << endl;
	}
	
	return 0;
}
