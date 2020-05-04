// This program generates all prime numbers smaller than the 
// input given by the user.


#include<iostream>
using namespace std;

int main()
{
  int num,temp;
  
  cout<<"enter the number : ";
  cin>>num;
  	
	for(int i=num ; i>1 ; --i )
  	{   
	    temp=0;
  		
		for(int j=i/2 ; j>1 ; --j)
  		{
		  if (i%j==0)
		  {
		  ++temp;
		  break;
  	    	  }
  		}
	    
		if(temp==0 && i!=1)
  		    cout<<i<<endl;
		
		else;
	}			 
	
}
