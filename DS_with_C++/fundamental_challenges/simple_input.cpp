#include<iostream>
#include <string>
using namespace std;

int main() {
	string result;

	int n;
	long long sum = 0;

	cin >> n;
	sum += n;
	while (sum >= 0){
		result += to_string(n) + '\n';
		cin >> n;
		sum += n;
	}

	cout << result;


	return 0;
}

