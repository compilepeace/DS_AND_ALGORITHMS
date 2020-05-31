#include<iostream>
using namespace std;

int recPow(int x, int n, int dp[])
{	
	int a1, a2;

	if (n == 1)
		return x;

	if (dp[n/2] == 0){
		a1 = recPow(x, n/2, dp);
		dp[n/2] = a1;
	}
	else
		a1 = dp[n/2];

	if (dp[n/2] == 0) {
		a2 = recPow(x, n/2, dp);
		dp[n/2] = a2;
	}
	else
		a2 = dp[n/2];

	return (n & 1) ? a1*a2*x: a1*a2;

}

int main() {
	int x, n;
	cin >> x >> n;

	int dp[n] = {0};

	int result = recPow(x, n, dp);
	cout << result << endl;
	return 0;
}
