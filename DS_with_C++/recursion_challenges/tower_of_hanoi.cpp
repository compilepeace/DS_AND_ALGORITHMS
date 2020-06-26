#include<iostream>
using namespace std;

void toh(int n, char s, char h, char d)
{
	if (n == 0)
		return;

	toh(n-1, s, d, h);
	cout << "Moving ring " << n << " from " << s << " to " << d << endl;
	toh(n-1, h, s, d);
}


int main() {
	int n;
	cin >> n;

	toh(n, 'A', 'C', 'B');		// 'A' is the source, 'B' is destination, 'C' is helper

	return 0;
}
