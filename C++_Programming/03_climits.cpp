#include <iostream> 
#include <climits>

using namespace std;


int main()
{
	fprintf(stderr, "INT_MAX    : 0x%x or %d \n", INT_MAX, INT_MAX);
	fprintf(stderr, "INT_MIN    : 0x%x or %d \n", INT_MIN, INT_MIN);
	fprintf(stderr, "INT_MAX + 1: 0x%x or %d \n", INT_MAX + 1, INT_MAX + 1);


	cout << "sizeof(long long): " << sizeof(long long) << "\n";

	return 0;
}
