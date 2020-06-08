#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2)
{
	// first sort them on the basis of salary
	if (p1.second > p2.second)
		return 1;

	// If both employees have same salary
	else if (p1.second == p2.second)
		return (p1.first < p2.first) ? 1: 0;

	// If p2 has greater salary than p1	
	else
		return 0;
}

int main() {
	int x;
	cin >> x;

	int n;
	cin >> n;

	vector<pair<string, int>> result;

	for (int i = 0; i < n; ++i)
	{
		string name;
		int salary;
		cin >> name >> salary;

		if (salary >= x)
		{
			pair<string, int> p;
			p.first = name;
			p.second = salary;

			result.push_back(p);
		}
	}

	sort(result.begin(), result.end(), compare);

	for (auto p: result){
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
