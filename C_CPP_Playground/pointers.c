#include<stdio.h>
#define n 10
void max_min(int a[] , int *max , int *min);

int main()
{
	int b[n], big , small , i;
	printf("\nEnter 10 numbers : \n");
	
	for(i=0 ; i<10 ; ++i)
	{
		scanf("%d",&b[i]);
	}
	max_min( b , &big , &small );
	printf("maximum value is : %d \nminimum value is : %d",big,small);
	return 0;
}

void max_min(int a[n],int *max ,int *min )
{	int i;
	*max=*min=a[0];
	for(i=0 ; i<10 ; ++i)
	{
		if(a[i] > *max)
			*max = a[i];
		if(a[i] < *min)
			*min = a[i];	
	}

}

