#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n , digit , sum=0 , k ;
	cout<<"\n\nEnter the number : ";
	cin>>n;
	k=n;								// k variable so that value of n does not alter
	do
	{
		if( k<10 && k>0)
			{
				digit = k;
				sum = sum + pow(digit,3);
				k=k/10;
			}
		else
			{
				digit = k%10;
				k = k/10;
				sum = sum + pow(digit,3);
			}	
	}while(k!=0);
	
	cout<<"\nSum of cubes of digits of number is : "<<sum<<"\n";

	if(sum == n)
		{
			cout<<"\n\t\tNumber is ARMSTRONG number !!";
		}
	else 
	        cout<<"\n\t\tNot an armstrong number !!\n\n";	
}
