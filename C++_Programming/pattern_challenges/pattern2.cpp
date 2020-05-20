#include<iostream>
using namespace std;

void printPattern(int n){

	cout << '1' << endl;
	if (n == 1) return;

	for (int i = 1; i < n; ++i){
		cout << i;
		for (int j = 0; j < i - 1; ++j)
			cout << '0';
		cout << i << endl;
	}
}
int main() {
	
	int n;
	cout << "Enter the height of pattern: ";
	cin >> n;

	if ( n < 1)
		return 0x1;

	printPattern(n);
	
	return 0;
}
