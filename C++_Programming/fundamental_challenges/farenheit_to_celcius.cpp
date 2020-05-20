#include<iostream>
using namespace std;

void printCelcius(int min, int max, int counter){

	int result = 0;
	for( int i = min; i <= max; i += counter){
		result = (int )((5.0/9.0)*(i - 32));
		cout << i << '\t' << result << endl;
	}
}


int main() {
	int min = 0, max = 0, counter = 0;

	cin >> min >> max >> counter;
	printCelcius(min, max, counter);
	return 0;
}
