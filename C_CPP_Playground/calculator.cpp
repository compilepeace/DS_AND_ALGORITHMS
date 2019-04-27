// This is a program for a simple calculator .

#include<iostream>
using namespace std;
int main()
{
 char ch; 
 double a,b;
 int n;
 	
 	do
	{
 	 cout<<"1. multiplication "<<endl;
     cout<<"2. division "<<endl;
     cout<<"3. subtraction "<<endl;
     cout<<"4. addition "<<endl;
     cout<<"enter the operation to be performed: "<<endl;
     cin>>n;	

		switch(n)
		{ 
			case 1: cout<<"enter the numbers ";
		            cin>>a>>b;
		            cout<<"product of numers entered is : "<<a*b;
		            break;
		    case 2: cout<<"enter the numbers ";
		            cin>>a>>b;
			        cout<<"quotient of numbers enterd is : "<<a/b;
				    break;
		    case 3: cout<<"enter the numbers ";
		            cin>>a>>b;
			  	    cout<<"difference of two numbers is : "<<a-b;
			  	    break;
		    case 4: cout<<"enter the numbers ";
		            cin>>a>>b;
			  	    cout<<"sum of numbers entered is : "<<a+b;
			  	    break;
		    default : cout<<"somebody on road raped you (SORRY)";	  		  		          
		};
		 
	 cout<<"\n"<<"do you want to enter more ? (y/n)"<<endl<<endl;
	 cin>>ch;
	
	}while(ch=='y' || ch=='Y'); 

return 0;
}
