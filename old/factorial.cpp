#include<iostream>
using namespace std;
int main()
{ int n,fact=1;
  cout<<"enter the digit not more than 16  ";
  cin>>n;
  for(int i=n ;i>=1 ; --i)
  {
   fact=fact*i;
  }
  cout<<fact;  
}
