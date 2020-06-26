#include<iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;

void getComb(int a[], int i, int n, int k, string str = "")
{
	if ( i == n ){
		if (k == 0){
			s.insert(str);
		}
		return;
	}

	getComb(a, i + 1, n, k - a[i], str + to_string(a[i]) + " " );
	getComb(a, i + 1, n, k, str);
}	

int main() {
	int n, k;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	cin >> k;

	sort(a, a + n);

	getComb(a, 0, n, k);

	for (auto e: s)
		cout << e << endl;

	return 0;
}
