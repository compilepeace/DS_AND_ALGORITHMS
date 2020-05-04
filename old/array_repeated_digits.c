// The entered number is broken into digits and then those digits 
// are stored in an array and furthur operations are performed
// on the array to check repetetion of digits.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int arr[20], arr_cpy[20] = {0};
	int i=0 , number, j, x, y, y_, rem, iter = 0 ;
	int size;

		if( argc < 2 )
			{
				printf("USAGE: %s <number> \n", argv[0]); 
				exit(0);	
			}	

					
		number = atoi(argv[1]);
		size = strlen(argv[1]);
		printf("Number entered: %d\nhaving %d digits\n", number, size);



			//enter digits in array to perform operations
			for( i=size-1 ; i>=0 ; --i )
				{
					rem = (number % 10);
					//printf("rem: %d\n", rem);
						if( number/10 != 0 )
							{
								number = number / 10;
								//printf("Storing: %d \n", rem);
								arr[i] = rem;
							}		
						else
							{
								arr[i] = rem;
								//printf("Storing: %d \n", rem);
							}
				}	

			//print array
			for( j=0 ; j<size ; ++j )
				{
					printf("%d ", arr[j]);
				} 	
			printf("\n");	
				


					//copy "unique" elements of one array to another
					for( x=0 ; x < size ; ++x )
						{
							++iter;
							if( x == 0 )
								{
									arr_cpy[x] = arr[x];
								}
								
							else		
								{
									//checking
									for( y=0 ; y<x ; ++y )
										{
											if( arr[x] == arr_cpy[y] )
												{
													printf("repeated number: %d\n", arr[x]);
													break;
												}	

											else
												arr_cpy[iter-1] = arr[x];	
										} 
								}
						}

						//print arr_cpy
						/*for( y_=0 ; y_<size ; ++y_ )
							{ 
								printf("arr_cpy[%d]: %d\n", y_, arr_cpy[y_]);
							}
						*/

return 0;
}