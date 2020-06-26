#include<iostream>
#include <string>
using namespace std;

void runLengthEncoding(string s, int i, string &o, int count = 0)
{
	if (i == s.length()){
		o += to_string(count);
		return;
	}

	if (i == 0){
		o = s[i];
		return runLengthEncoding(s, i + 1, o, count + 1);
	}

	// If current element is same as previous element
	if (s[i] == s[i - 1]){
		runLengthEncoding(s, i + 1, o, count + 1);
	}

	// If current element is a different element than previous one
	else{
		o += to_string(count);
		o += s[i];
		runLengthEncoding(s, i + 1, o, 1); 
	}
}

int main() {
	string s, o;
	cin >> s;

	runLengthEncoding(s, 0, o);
	cout << o;

	return 0;
}
