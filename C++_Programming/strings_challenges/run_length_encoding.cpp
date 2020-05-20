#include<iostream>
#include <sstream>              // To use string stream 
using namespace std;



char *runLengthEncoding(string s)
{
	char *result = (char *)malloc( (2 * s.size()) + 1);
	char *ptr = result;

	int i = 0;
	int count = 1, scale = 0;
	
	while (s[i] != '\x00'){

		// If not equal to the next char
		if (s[i] != s[i + 1]){
			scale += sprintf(ptr + scale, "%c%d", s[i], count);
			count = 0;
		}

		++count;
		++i;
	}
	*(ptr + scale) = '\x00'; 			// End the resulting string with a NULL char

	return result;
}


// Using string stream c++ to convert int into a string 
//            stringstream ss;
//            ss << count;                // extract 'count' (int) into string stream.
//            ss >> num;                  // insert 'count' (int) into 'num' (string) from string stream
//            result += s[i] + num;
// Using to_string() function to convert 'count' (int) to a string
string compress(string s)
{
    string result;

    int i = 0, count = 1;
    while (s[i] != '\x00'){

        if (s[i] != s[i + 1]){
            result += s[i] + to_string(count);    
            count = 0;
        }
        ++count;
        ++i;
    }

    return result;
}


int main() {
	
	string s;

	getline(cin, s);

	char *result = runLengthEncoding(s);
	cout << "C style  : " <<  result << endl;
	
    string ans = compress(s);
    cout << "c++ style: " << ans << endl;
    return 0;
}
