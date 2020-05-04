#include <iostream>
using namespace std;

int main()
{
	char ch = cin.get();

	while (ch != '.')
	{
		cout << ch;
		ch = cin.get();
	}

}
