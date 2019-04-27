#include<iostream>
using namespace std;
char hexcode(int digit)
{
	return "0123456789abcdef"[digit];
}
int main()
{	char ch;
	int d;
	cout<<"Enter the code :";
	cin>>d;
	ch = hexcode(d);
	cout<<ch;
	
}
