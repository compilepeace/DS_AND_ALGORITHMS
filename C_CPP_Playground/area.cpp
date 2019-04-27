#include<iostream>
using namespace std;
int rectangle();
int triangle();
int square();
int main()
{	
	int ch, area=0;
	char m;
	do
	{
	cout<<"1. Area of rectangle \n";
	cout<<"2. Area of triangle \n";
	cout<<"3. Area of square \n";
	cout<<"Enter the choice ";
	cin>>ch;
	
	switch(ch)
	{
		case 1 : area = rectangle();
				 cout<<"\n\t\t Area of rectangle is :"<<area;
				 break;
		case 2 : area = triangle();
				 cout<<"\n\t\t Area of triangle is :"<<area;
				 break;
		case 3 : area = square();
				 cout<<"\n\t\t Area of square is :"<<area;
				 break;		 		 
				 
	}
	cout<<"\ndo you want to enter more (y/n): ";
	cin>>m;
	}while(m=='y'||m=='Y');
}

int rectangle()
{	int l,b,a;
	cout<<"Enter the length and breadth :";
	cin>>l>>b;
	a=l*b;
	return a;	
}
int triangle()
{
	int b,h,a;
	cout<<"Enter the base and height :";
	cin>>b>>h;
	a=(b*h)/2;
	return a;
}
int square()
{
	int s,a;
	cout<<"Enter the side of square :";
	cin>>s;
	a=s*s;
	return a;
}
