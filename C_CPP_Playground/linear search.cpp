#include<stdio.h>

int array[500];

int *input(int size_array)
{	
	int i = 0 , j , num ;
	printf("Enter the numbers in ascending order : ");
		
		for( i=0 ; i < size_array ; ++i )
		{	
			printf("Eneter [%d] element :" , i );
			 	scanf( "%d" , &array[i] ) ;
		}
		
/*		for( j=0 ; j<size_array ; ++j)				to test the array
			printf("%d\n", array[j]);
*/			
return array;		
}

/******************************	Linear Search	*****************************/

		int linear_search( int number , int size )
		{
			int i=0 , flag=0 ;
				for( i=0 ; i<size ; ++i)
				{
					if( array[i] == number )
						{
							printf("\nThe number %d found at position %d ", array[i] , i);
							flag = 1 ;
							break;
						}
						
				}
			if( flag == 0 )
				printf("Number not found ! ");	
		}
	
/***************************************************************************/	

int main()
{
	int *address , number = 0 , size ;						//will contain address of the array returned by input() 
		
	printf("\nEnter the number of elements to be entered :");
	scanf("%d" , &size)	;
	
		address = input(size) ;
		
	printf("\nEnter the number to be searched : ");
	scanf("%d", &number ) ;
		
		linear_search( number , size );

return 0;		
}
