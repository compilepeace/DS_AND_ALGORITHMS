#include<iostream>

using namespace std;

int main()
{
	int var1=4, var2=1;
	
	
		//rows
		for(int row=0; row<5; ++row)
		{
			
			//spaces
			for(int space=var1; space>=0; --space)
				cout<<" ";
		--var1;	
			
			//numbers
			for(int column=0 ; column < (2*row)+1 ; ++column)
			{
				if(column%2 != 0)
					cout<<" ";
				
				else
					cout<<var2;
			}
			
		++var2;		
		cout<<"\n";		
		}
	
return 0;	
}
