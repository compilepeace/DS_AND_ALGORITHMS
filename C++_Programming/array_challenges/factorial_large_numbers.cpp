#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

string factorial(int n)
{
	string result("1");
	for (int x = 1; x <= n; ++x)
	{
		int len = result.size();
		int carry = 0;

		// Iterate over the string
		for (int i = 0; i < len; ++i){
			int value = ((result[i] - 48) * x ) + carry;
			result[i] = (value % 10) + 48;			// Put the last digit into result[i]
			carry = value/10;				// Remove last digit from value;
		}

		// append carry to the end of result
		while (carry != 0)
		{
			int digit = (carry % 10);
			result += to_string(digit);  
			carry = carry / 10;
		}
		//cout << result << endl;
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string result;
	int n; 
	cin >> n;

	result = factorial(n);
	cout << result;
	return 0;
}
