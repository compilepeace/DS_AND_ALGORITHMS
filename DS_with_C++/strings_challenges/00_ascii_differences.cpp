#include<iostream>
#include <string>
using namespace std;

int main() {
	int i = 0;
	string s;

        // Take a string as input from the user
		// It has a 3rd optional argument (delimiter char *)
        getline(cin, s);

        
		/*
		for (auto chr: s)
			cout << chr << ":";
		*/
		
		if (s.size() >= 2){
			for (i = 0; i < s.size() - 1; ++i)
			{
				cout << s[i] << s[i+1] - s[i];
			}
			cout << s[i];
		}

	return 0;
}
