#include<iostream>
using namespace std;

bool isPalindrome(int a[], int n)
{
	int start = 0;
	int end = n - 1;

	while (start < end)
	{
		if (a[start++] != a[end--])
			return false;
	}
	return true;
}

int main() {
	int n; 
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool result = isPalindrome(a, n);
	if (result)
		cout << "true";
	else
		cout << "false";

	return 0;
}
