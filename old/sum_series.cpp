//7. print the series 

#include<stdio.h>
int factorial(int n)
{	
	int i,fact=1;
	for(i=1 ; i<=n ; ++i)
     	fact=fact*i;	
return fact;	
}
int main()
{
	//factorial(3);
	int terms,i,j;
	float float_var,sum=0.0f;
	printf("enter the number of terms of series :");
	scanf("%d",&terms);
	
		for(i=1,j=1 ;  j<=terms ; i=i+2,++j )							//i is for numerator and j is for denominator
		{	
			float_var = (float)i/(float)factorial(j);					//explicit type casting
			sum = sum + float_var;
			printf("%f\n",sum);
		}
	
	printf("the sum of the given series is : %f",sum);

return 0;		
}
