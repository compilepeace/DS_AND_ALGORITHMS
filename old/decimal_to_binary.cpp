#include<iostream>
using namespace std;
int main()
{
	int n,rem[30],flag=0,m;
	cout<<"enter the number \t";
	cin>>n;
    for(int i=0;n>0;++i)
    {
		rem[i]=n%2;
    	n=n/2;
    		if (n==1)
    		{
				rem[i+1]=1;
    			m=++flag;
    			break;
    	    }
    	m=++flag; 						//gves number of digits enterd
    }
    for(int j=m;j>=0;--j)
    {
	 	cout<<rem[j];
	}
}
