#include<iostream>

using namespace std;

int main()
{
	int n, sum;
	
	cout<<"Enter the order of array: ";
	cin>>n;
	
	//variable-length array
	int array[n][n];
	

		//taking input in array
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cin>>array[i][j];			
			}
		}
		
		//outputting elements
		for(int x=0; x<n; ++x)
		{
			cout<<endl;
			for(int z=0; z<n; ++z)
			{
				cout<<array[x][z]<<" ";			
			}
		}
		cout<<endl;
		
		//summing the elements of row
			for(int k=0; k<n; ++k)
			{
				sum = 0;
				
					for(int l=0; l<n; ++l)
					{
						sum = sum + array[k][l];						
					}
				cout<<"sum of "<<k+1<<" row is: "<<sum<<endl;
			}
			
return 0;			
	
}

