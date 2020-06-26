#include<iostream>
using namespace std;


int maxProfit(int a[], int s, int e)
{
	int pickFirst, pickLast;

	if (s > e){
		return 0;
	}

	// If I pick coin the start
	// The opponent will try to minimize my profit
	// i.e. opponent will pick the element such that the maxProfit I can get after it is minimum.
	pickFirst = a[s] + min( maxProfit(a, s + 1, e - 1), maxProfit(a, s + 2, e) );

	// If I pick coin from the end
	// i.e. opponent will pick the element such that the maxProfit I can get after it is minimum.
	pickLast = a[e] + min( maxProfit(a, s + 1, e - 1), maxProfit(a, s, e - 2));

	return max(pickFirst, pickLast);
}

int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n;  ++i)
		cin >> a[i];

	cout << maxProfit(a, 0, n-1);
	return 0;
}
