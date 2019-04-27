#include<iostream>
using namespace std;
int main()
{ int height,flag=1,var=0;
  
  cout<<"enter the height of pyramid : ";
  cin>>height;
  cout<<endl;
  
  var=height;

	for(int i=1; i<=height ;++i)                                    //i = line no.
	 {  

	   		for(int s=var-1; s>=0; --s)                        //s = spaces
  	   		    cout<<" ";
  			 
		var=var-1;                                        //impo.
  	 			
			for(int x=0; x<2*i-1; ++x)                    //x = *
	  			cout<<"*";
       			 
	  cout<<endl;
     }
return 0;     
}

