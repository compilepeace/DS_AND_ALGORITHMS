// Input only contains - 0, 1 or 2


#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];

	pair<int, int> p0 = make_pair(0, 0);
	pair<int, int> p1 = make_pair(1, 0);
	pair<int, int> p2 = make_pair(2, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];

		if (a[i] == 0)
			p0.second += 1;

		else if (a[i] == 1)
			p1.second += 1;
	
		else
			p2.second += 1;
	} 

	for (int i = 0; i < p0.second; ++i)
		cout << p0.first << endl;
	
	for (int i = 0; i < p1.second; ++i)
		cout << p1.first << endl;

	for (int i = 0; i < p2.second; ++i)
		cout << p2.first << endl;

	return 0;
}
