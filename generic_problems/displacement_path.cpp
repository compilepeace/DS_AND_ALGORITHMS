#include <iostream>
using namespace std;

int main()
{
	int x = 0, y = 0;

	char ch = cin.get();

	while (ch != '\n')
	{
		if (ch == 'E' || ch == 'e')
			++x;
		
		else if (ch == 'W' || ch == 'w')
            --x;

		else if (ch == 'N' || ch == 'n')
            ++y;

		else if (ch == 'S' || ch == 's')
            --y;
		
		ch = cin.get();
	}

	cout << "Final displacement from (0,0): [" << x << "," << y << "]\n";	
	
	while (y != 0)
	{
		if ( y > 0 ){
			cout << 'N';
			--y;
		}
		
		else if ( y < 0 ){
			cout << 'S';
			++y;
		}
	}	

	while ( x != 0 )
	{
		if ( x > 0 ){
			cout << 'E';
			--x;
		}
		
		else if ( x < 0 ){
			cout << 'W';
			++x;
		}
	}
	
	cout << "\n";
}
