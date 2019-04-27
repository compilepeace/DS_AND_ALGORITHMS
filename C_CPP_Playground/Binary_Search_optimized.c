#include<stdio.h>

int array[500];

/*************************	Binary Search	***************************/

int binary_search( int number , int size )
{
	int first=0 , last=size-1 , mid=size/2 , flag=0 ;
	
	
	//	printf("%d %d " , first , last );
	
	if( number < array[first] || number > array[last] )
		printf("The number does not exist !\n ");							//This eliminates one possibility of the worst case scenario of binary search
																		//i.e. when the number to be searched is out of bound of numbers entered
	else
	{
		for( ;  ; )
		{	
			//before checking any middle idex or anything
			//check wether the number is present at the first or last index 
						if( number == array[first] )
							{
								printf("Number found at %d position " , first + 1 );
								flag=1 ;
								break;			
							}
						if( number == array[last] )
							{
								printf("Number found at %d position " , last + 1 );
								flag=1 ;
								break;			
							}

			//then check the middle index				
			if( number == array[mid] )
			{
				printf("Number found at %d position " , mid + 1 );
				flag=1 ;
				break;			
			}
					 	
					 	//shift to the later half  
						if( number > array[mid] )
						{			
									//before going to the middle index for checking , check the index where the first and last currently are
									if( number == array[first] )
										{
											printf("Number found at %d position " , first + 1 );
											flag=1 ;
											break;			
										}
									if( number == array[last] )
										{
											printf("Number found at %d position " , last + 1 );
											flag=1 ;
											break;			
										}
							//increments the first to one index ahead and decrements the last index by one index			
							first = mid + 1 ;
							last = last - 1 ;
									
									//before checking the middle check the first and last index
									if( number == array[first] )
										{
											printf("Number found at %d position " , first + 1 );
											flag=1 ;
											break;			
										}
									if( number == array[last] )
										{
											printf("Number found at %d position " , last + 1 );
											flag=1 ;
											break;			
										}	
							
							//place the middle
							mid = (first + last) / 2 ;						
						}
			
			//shift to the first half of the array 
			else if( number < array[mid] )
			{
				//checks the number at first and last index before checking the middle element
						if( number == array[first] )
							{
								printf("Number found at %d position " , first + 1 );
								flag=1 ;
								break;			
							}
						if( number == array[last] )
							{
								printf("Number found at %d position " , last + 1 );
								flag=1 ;
								break;			
							}
				
				last = mid - 1 ;							
				first = first + 1 ;
				
				//checks the number at first and last index after incrementing first(to next place) and decrementing last(just before middle index)		
						if( number == array[first] )
							{
								printf("Number found at %d position " , first + 1 );
								flag=1 ;
								break;			
							}

						if( number == array[last] )
							{
								printf("Number found at %d position " , last + 1 );
								flag=1 ;
								break;			
							}	
							
				//placing middle at the index between the incremented first and decremented last index
				mid = (first + last) / 2 ;
			}
		
				if( mid == first || mid == last )					//if number is not present in the list
					break;	
		}
		
		// if value of flag does not change after incrementing the loop , the number is not present
		if(flag != 1)
			printf("Number not found ! \n");	
	}
	
}

/***********************************************************************/

int *input(int size_array)
{	
	int i = 0 , j , num ;
	printf("(Enter the numbers in ascending order) \n ");
		
		for( i=0 ; i < size_array ; ++i )
		{	
			printf("Enter [%d] element :" , i+1 );
				scanf( "%d" , &array[i] ) ;
		}
		
		for( j=0 ; j<size_array ; ++j)
			printf("%d\n", array[j]);
			
return array;		
}

		
int main()
{
	int *address , number = 0 , size ;						//will contain address of the array returned by input() 
		
	printf("\nEnter the number of elements to be entered :");
	scanf("%d" , &size)	;
	
		address = input(size) ;
		
	printf("\nEnter the number to be searched : ");
	scanf("%d", &number ) ;
		
		binary_search( number , size );

return 0;		
}
