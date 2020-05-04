#include<iostream>
using namespace std;
int main()
{
	int x[30],n;
	cout<<"how many digits you want to enter ?  ";
	cin>>n;
		for(int i=0 ; i<n ; ++i)
		{
		  	cin>>x[i]; 
		}
			for(int j=0; j<n ; ++j)
			{
				if(x[j]%2==0)
				{cout<<"even no. '"<<x[j]<<"' at position : "<<j+1<<endl;
				}
			}
}
