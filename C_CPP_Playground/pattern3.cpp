#include<iostream>

using namespace std;

int main()
{
	int var1=5, var2=1, mid=0;
	
	
		//rows
		for(int row=1; row<6; ++row)
		{
			
			//spaces
			for(int space=var1; space>0; --space)
				cout<<" ";
		var1 = var1 - 1;	
			
			
			mid = row;
			//numbers			
					if(mid == 1)	
						cout<<var2;
					
						else 
						{
							for(int j=1; j<(mid+1); ++j)
								cout<<j;
							
							for(int k=mid-1; k>0; --k)
								cout<<k;	
						}				
					
		cout<<"\n";		
		}
	
return 0;	
}
