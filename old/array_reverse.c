#include<stdio.h>

#define N 9

int main()
{
	int array[N];
	int i, j;

		//scan
		for( i=0 ; i<N ; ++i )
			{
				printf("Enter the %d element: ", i+1);
				scanf("%d", &array[i]);
				printf("\n");
			}

		//print	
		printf("In reverse order: ");
				
			for( j=N ; j>0 ; --j )
				{
					printf("%d ", array[j-1]);	
				}	

		printf("\n");		

return 0;
}