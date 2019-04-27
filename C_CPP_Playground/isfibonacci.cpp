//6. fibonacii series or not

#include<stdio.h>
int main()
{	
	int n,i,j,flag;
	
	printf("how many numbers do u want to enter in the series :");
	scanf("%d",&n);
	
	int series[n-1];													// n is length of the array
	
		for( i=0; i<n-1 ; ++i )										//function to take input of series
		{
			scanf("%d ",&series[i]);
		}
		
		for( j=2 ; j<n-1 ; ++j )
		{   
			if(series[j]!=series[j-1]+series[j-2])
		    {printf("not a fibonacci series !!");
			 break;
		    }
			else 
				flag=10;											//variable that does not alter only if the condition 
																	//if series is fibonacci
		}
	if(flag==10)
	printf("it is a fibonacci series !!");
	else if(n==3 && series[0]==0 && series[1]==1 && series[2]==1)
	printf("is a fibonacci series !!");
	else if(n==2 && series[0]==0 && series[1]==1 )
	printf("is a fibonacci series !!");
	
	
		
	
	
}
