#include<iostream>

using namespace std;


int main()
{
	int num, col=0, counter=1, var=2;

	cout<<"Enter a number: ";
	cin>>num;
	
	//variable
	var = 2;

	if (num < 1)
	{
		cout<<"Not a valid number";
		return 1;
	}

	else
	{
		//print first line as it is
		while( col < num )
		{
			cout<<(col+1)<<"*";
		 	++col;
		}
		
		cout<<"\n";
	
		//start printing from second line
		for(int row_counter=2; row_counter < (num+1); ++row_counter)
		{

		 counter = (num * var) + 1;	

			for(int col_counter=1; col_counter < (num+1); ++col_counter)

			{
				//counter = (var * 2) + 1;
				cout<<counter<<"*";
				++counter;
			}
		
			cout<<"\n";
			//altering value of var
			
			//if num== odd
			if( num%2 != 0)
			{
				if( row_counter < (num/2) + 1)
					var = var + 2;
	
				else if( row_counter == (num/2) + 1)
					var = var - 1;
				
				else 
					var = var - 2;
			}

			//if num==even
			if( num%2 == 0)
			{
				if(row_counter < (num/2))
				{
				
					var = var + 2;
					//cout<<"DEBUG:var"<<var<<" ";

				
				}
				else if(row_counter == ((num/2)))
				{
					//cout<<"row_counter"<<row_counter;			
					var = var + 1;
					//cout<<"MDEBUG:var"<<var<<" ";	
				}
				else 
				{
					
					var = var - 2;
					//cout<<">DEBUG:var"<<var<<" ";

				}
			}
		
		}	
	}
return 0;
}
