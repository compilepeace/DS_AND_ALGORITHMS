#include<iostream>
using namespace std;
int main()
{ 
	int n;
	cout<<"enter the number : ";
	cin>>n;
	int arr[n]={0,1};
	cout<<arr[0]<<"\t"<<arr[1]<<"\t";
		for(int i=2; i<n ; ++i)
		{
			arr[i]=arr[i-1]+arr[i-2];
			cout<<arr[i]<<"\t";
		}
	cout<<"\n"<<arr[n-1]<<"\n";
	
}

