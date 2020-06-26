#include<iostream>
#include <string>
using namespace std;

void removeDuplicates(string &a, int i, int j)
{
	if (a[i] == '\0'){
		a[j] = '\0';
		return;
	}

	if (a[i] == a[i - 1]){
		return removeDuplicates(a, i + 1, j);
	}
	else{
		a[j] = a[i];
		return removeDuplicates(a, i + 1, j + 1);
	}
}

int main() {

	string s;
	cin >> s;

	removeDuplicates(s, 1, 1);

	cout << s.c_str();				// Print the C string (in which '\0' marks as the end of string)

	return 0;
}
