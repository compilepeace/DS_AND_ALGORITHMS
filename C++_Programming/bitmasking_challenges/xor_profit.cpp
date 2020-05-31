#include<iostream>
#include <climits>
using namespace std;

int main () {

	int a, b;
	int ans = INT_MAX;

	cin >> a >> b;

	for (int i = a, i <=b; ++i)
	{
		for (int j = i; j <=b; ++j)
		{
			ans = max(ans, i^j);
		}
	}

	cout << ans;
	
	return 0;
}
