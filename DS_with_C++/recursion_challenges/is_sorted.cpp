#include<iostream>
using namespace std;

bool isSorted(int a[], int e, int i = 0)
{
	if (i == e)
		return true;
	
	if (a[i] > a[i + 1])
		return false;

	return isSorted(a, e, i + 1);

}

int main() {

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bool status = isSorted(a, n - 1);
	if (status == true)
		cout << "true";
	else
		cout << "false";

	return 0;
}
