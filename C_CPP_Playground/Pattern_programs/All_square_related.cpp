/*************************************************************************
*
* All_square_related.cpp
*
*
* Abhinav Thakur	
* compilepeace@gmail.com
*
*
* Prints out various square relating patterns
*
*************************************************************************/ 


#include <iostream>
using namespace std;

void simple_charecter_square(int );
void square_number_pattern1(int );
void square_number_pattern2(int );
void square_alphabet_pattern1(int );
void square_alphabet_pattern2(int );


int main()
{
	int i, j;
	int num;
	int choice;
	char choose;
	
	do
	{
		cout<<"\n\nEnter the side of the square: ";
		cin>>num;
		cout<<endl;
		
		cout<<"\n\n";
		cout<<"Select the output type: \n\n";
		cout<<"1. simple_charecter square\n";
		cout<<"2. square made up of numbers alligned in a row\n";
		cout<<"3. square made up of numbers alligned in a column\n";
		cout<<"4. square made up of alphabets alligned in a row\n";
		cout<<"5. square made up of alphabets alligned in a column\n";
		cout<<endl;
		cout<<"\n\tYour choice --> ";
		cin>>choice;
	
			if(choice < 1 || choice > 5)
			{
				cout<<"\nPlease Enter a valid choice \n\n";
				exit(0);
			}
		
			else if (choice == 1)
				simple_charecter_square(num);
			
			else if (choice == 2)
				square_number_pattern1(num);
			
			else if (choice == 3)
				square_number_pattern2(num);
		
			else if (choice == 4)
				square_alphabet_pattern1(num);			
		
			else if (choice == 5)
				square_alphabet_pattern2(num);
					
		
		cout<<"\n\n";
		cout<<"Do you want to have more outputs ?(Y/N) -> ";
		cin>>choose;
	
	}while(choose == 'Y' || choose == 'y');
	
return 0;		
}


void simple_charecter_square(int n)
{
	
	int i, j;
	
		for(i=0 ; i<n ; ++i)
		{
			cout<<"\n";
			
			for(j=0; j<n; ++j)
			{
				cout<<"*"<<" ";
			}
		}
}


void square_number_pattern1(int n)
{
	
	int i, j;
	int counter=0;
	
	if(n>9)
		cout<<"\nWarning: Pattern will not be a perfect square..\n";

		for(i=0 ; i<n ; ++i)
		{
			counter += 1;
			cout<<"\n";
			
			for(j=0; j<n; ++j)
			{
				if(n<10)
					cout<<counter<<" ";
				
				else
					cout<<counter;
				
			}
		}
}


void square_number_pattern2(int n)
{
		int i, j;
	
		for(i=0 ; i<n ; ++i)
		{
			cout<<"\n";
			
			for(j=0; j<n; ++j)
			{
				cout<<j+1<<" ";
			}
		}
	
}


void square_alphabet_pattern1(int n)
{
		int i, j;
	
	
		for(i=0 ; i<n ; ++i)
		{
			cout<<"\n";
			
			for(j=0; j<n; ++j)
			{
				cout<<(char)('A'+i)<<" ";
			}
		}
}


void square_alphabet_pattern2(int n)
{
		int i, j;
	
	
		for(i=0 ; i<n ; ++i)
		{
			cout<<"\n";
			
			for(j=0; j<n; ++j)
			{
				cout<<(char)('A'+j)<<" ";
			}
		}
}
