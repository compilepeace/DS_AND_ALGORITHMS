/***************************************************************
***  This checks the first and the last charecters of the    ***
***  string entered and everytime it comes out to be the same***
***  it assigns flag=1 . so when the loop ends, all 		 ***
***  charecters are checked and value of flag=1 if not 1     ***
***  then not a pallindrome . the else statement is executed ***
***  if string is not a pallindrome and program exits        ***
***  printing NO.											 ***
***************************************************************/


#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int length , i , flag=0 ;
	char s[100+1];
	gets(s);
		length=strlen(s);
		
		if(length== 1)												
			cout<<"String is of insufficient length ! \n";
			
		else		
		{
			
			for( i=0 ; i<length ; ++i)
			{
				if(s[i]==s[length-i-1])								
					flag=1;
				else
					{
						cout<<"NO";									//NOT a pallindrome
						exit(0);		
			        }
		    }
		}
		
		if(flag)
			cout<<"YES";											//YES it is a pallindrome

		
return 0;		
}
