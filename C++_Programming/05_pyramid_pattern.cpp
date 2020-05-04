/*

Print pattern - 

    1
   232
  34543
 4567654
567898765

*/



#include <iostream>


using namespace std;


/*
=> Iterate over rows and print columns for each row
1. Print spaces
2. Print increasing numbers
3. Print decreasing numbers
4. Print a newline
*/
void printPyramid(int h)
{

	// iterate over rows	
	for (int i = 1; i <= h; ++i)
	{
		int j;

		for (j = 1; j <= (h-i); ++j)			// <1>
			cout << ' ';

		int elements_in_row = 1 + (i - 1) * 2;		// nth term of an A.P = a + (n - 1)*d
		int hops = elements_in_row/2;

		for (j = i; j < (i + hops); ++j)		// <2>
			cout << j;
	
		for (; j >= i; --j)						// <3>
			cout << j;

		
		cout << "\n";			// <4>
	}
}



int main() 
{
	int height; 

	cout << "Enter the height of pyramid: ";
	cin >> height;

	printPyramid(height);

	return 0;
}
