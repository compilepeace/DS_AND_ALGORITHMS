/*************************************************************************
*
* All_right_angled_triangle.cpp
*
*
* Abhinav Thakur	
* compilepeace@gmail.com
*
*
* Prints out various patterns realting to right_angled or half triangles
*
*************************************************************************/ 


#include <iostream>
using namespace std;

void left_triangle(int );
void left_UpSideDown(int );
void right_triangle(int );
void right_UpSideDown(int );
void left_triangle_star(int );
void right_triangle_star(int );

int main()
{
	int i, j;
	int num;
	int choice;
	char choose;
	
	do
	{
		cout<<"\n\nEnter the height of right angled triangle: ";
		cin>>num;
		cout<<endl;
		
		cout<<"\n\n";
		cout<<"Enter the position of right angled triangle you want to have: \n\n";
		cout<<"1. left_traingle\n";
		cout<<"2. left_UpSideDown triangle\n";
		cout<<"3. right_Triangle\n";
		cout<<"4. right_UpSideDown triangle\n";
		cout<<"5. left_triangle made of charecter you want\n";
		cout<<"6. right_triangle made of charecter you want\n";
		cout<<endl;
		cout<<"\n\tYour choice --> ";
		cin>>choice;
	
			if(choice < 1 || choice > 6)
			{
				cout<<"Please Enter a valid choice \n\n";
				exit(0);
			}
		
			else if (choice == 1)
				left_triangle(num);
			
			else if (choice == 2)
				left_UpSideDown(num);
			
			else if (choice == 3)
				right_triangle(num);
		
			else if (choice == 4)
				right_UpSideDown(num);			
		
			else if (choice == 5)
				left_triangle_star(num);
				
			else if (choice == 6)
				right_triangle_star(num);	
		
		cout<<"\n";
		cout<<"Do you want to have more outputs ?(Y/N) -> ";
		cin>>choose;
	
	}while(choose == 'Y' || choose == 'y');
	
return 0;		
}

// Prints right angled triangle with hypotenuse '\' 
void left_triangle(int n)
{
	
	int i, j;
	
		for(i=1 ; i<=n ; ++i)
		{
			cout<<"\n";
			
			for(j=0; j<i ; ++j)
			{
				cout<<(char)('A'+j)<<" ";
			}
		}		
		
}


// Prints right angled triangle turned Up-Side-Down(left)
void left_UpSideDown(int n)
{
		
	int i, j;
	
		for(i=n ; i>=1 ; --i)
		{
			cout<<"\n";
			
			for(j=i; j>0 ; --j)
			{
				cout<<(char)('A'+j-1)<<" ";
			}
		}		
	
}

// Prints right angled triangle with hypotenuse '/'
void right_triangle(int n)
{
		
	int row, spaces, star;
	char ch;
	
	cout<<"\nEnter the charecter you want the triangle to be comprised of: ";
	cin>>ch;
	cout<<"\n";
		
		if( ch>47 && ch<58)
		{
			cout<<"Enter a charecter, not a digit.";
			exit(0);
		}
	
		for(row=1 ; row<=n; ++row)
		{
			cout<<"\n";
				
				//for spaces
				for( spaces = (n-row) ; spaces>0 ; --spaces)
					cout<<" ";
					 			
				//for pattern
				for( star=row ; star>0 ; --star)
				{
					cout<<ch;
				}
		}
}

// Prints right angled triangle turned upside down(right)
void right_UpSideDown(int n)
{
		
	int row, spaces, star;
	char ch;
	
	cout<<"\nEnter the charecter you want the triangle to be comprised of: ";
	cin>>ch;
	cout<<"\n";
	
		if( ch>47 && ch<58)
		{
			cout<<"Enter a charecter, not a digit.";
			exit(0);
		}
	
		for(row=n ; row>=0; --row)
		{
			cout<<"\n";
				
				//for spaces
				for( spaces=n-row ; spaces>0 ; --spaces)
					cout<<" ";
					 			
				//for pattern
				for( star=row ; star>0 ; --star)
				{
					cout<<ch;
				}
		}		
}


// Prints left-side right angled triangle of any charecter user wants
void left_triangle_star(int n)
{
	int i, j;
	char ch;
	
	cout<<"\nEnter the charecter which makes up the right_triangle: ";
	cin>>ch;
	
		if( ch>47 && ch<58)
		{
			cout<<"Enter a charecter, not a digit.";
			exit(0);
		}

		for(i=1; i<=n ; ++i)
		{
			cout<<"\n";
			for(j=0 ; j<i ; ++j)
			{
				cout<<ch<<" ";
			}
		}
	
}


// Prints right-side right angled triangle of any charecter user wants
void right_triangle_star(int n)
{
	int row, counter=1, star, spaces;
	char ch;
	
	cout<<"\nEnter the charecter which makes up the right triangle: ";
	cin>>ch;
	
		if( ch>47 && ch<58)
		{
			cout<<"Enter a charecter, not a digit.";
			exit(0);
		}
	
		for(row=n; row>0 ; --row)
		{
			cout<<"\n";
			
			for(spaces=row-1 ; spaces>0 ; --spaces)
			{
				cout<<" ";
			}
			
			for(star=0 ; star<counter ; ++star)
			{
				cout<<ch;
			}
			
			++counter;
		}
}
