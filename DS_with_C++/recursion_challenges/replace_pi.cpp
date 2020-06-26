#include<iostream>
using namespace std;


void replacePi(string s, int i, string &o)
{
	if (i == s.length()){
		o += '\0';
		return;
	}
	
	if (s[i] == 'p' and s[i + 1] == 'i'){
		o += "3.14";
		replacePi(s, i + 2, o);
	}
	else{
		o += s[i];
		replacePi(s, i + 1, o);
	}
}

int main() {
	int n;
	cin >> n;
	cin.get();

	for (int i = 0; i < n; ++i){
		string s, o;
		cin >> s;

		replacePi(s, 0, o);
		cout << o.c_str() << endl;
	}
	return 0;
}
