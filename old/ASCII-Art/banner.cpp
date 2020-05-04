// Author : Abhinav Thakur
// Email  : compilepeace@gmail.com

// Description : Program takes in first name and prints out a banner to STDOUT(2)


#include <iostream>
#include <string>
#include <cstdint>

#define ROW 5

using namespace std;


// FUNCTION PROTOTYPES
void greeting(string, uintmax_t);



int main(int argc, char *argv[])
{
	
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <name>\n";
		exit(0x1);
	}	

		string name = "~ " + (string)argv[1] + " ~";	
		greeting(name, name.length());
	
return 0;
}


// First greeting
// We could alternatively use the 'std::string::size_type' as a type for 'msg_len' variable which 
// guarantees to store length of any arbitrarily long string.
void greeting(const string message, uintmax_t msg_len)
{

//	INTMAX_MIN and INTMAX_MAX defined in cstdint or <stdint.h> which denotes the smallest and largest
//	value the type intmax_t can hold and UINTMAX_MAX Macro denotes the largest value a variable of 
//	type uintmax_t can hold.
	
	if (msg_len > UINTMAX_MAX)
	{
		cout << "Name too long : " << msg_len << endl;
		exit(0x2);
	}
	
	// continue to next row (size programmer-dependent
	for (int r=0; r < ROW; ++r)
	{
		// print column character (size depending on user-input)
		for (int c=0; c < msg_len; ++c )
		{
			// if 1st row or last row
			if (r == 0 || r == (ROW-1))
				cout << '~';
			
			else 
			{
				// if 2nd row or 4th row, then only first col and last col should be '~'
				if ((r == 1 || r == 3))
				{
					if (c == 0 || c == (msg_len-1))
					cout << '~';
					
					else
					cout << ' ';
				}	
			}
		}

		if (r == 2)
			cout << message;	
		cout << "\n";
	}
}

