#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {

	int n, count = 0, rem;
	cin >> n;
	vector<int> v;

	while (n != 0){
		rem = n % 8;
		n = n / 8;
		++count;

		v.push_back(rem);
	}

	int result = 0;
	for (int i=0; i < v.size(); ++i){
		result += v[i] * pow(10, i);
	}
	
	cout << result;
	return 0;
}
