#include<iostream>
using namespace std;

void printResult(char ch)
{
	int a, b;

	switch(ch)
	{
		case '+': cin >> a >> b;
				  cout << a + b << endl; 
				  break;
		case '-': cin >> a >> b;
				  cout << a - b << endl; 
				  break;
		case '/': cin >> a >> b;
				  cout << a / b << endl; 
				  break;
		case '*': cin >> a >> b;
				  cout << a * b << endl; 
				  break;
		case '%': cin >> a >> b;
				  cout << a % b << endl; 
				  break;
		case 'x': 
		case 'X': return;
		default:  cout << "Invalid operation. Try again.\n";
				  break;
		
	}
}

int main() {

	char ch = '\x00';	

	do {
		cin >> ch;
		printResult(ch);
	}while (ch != 'x' && ch != 'X');

	return 0;
}
