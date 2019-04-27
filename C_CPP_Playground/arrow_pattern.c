#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int height = atoi(argv[1]);
	int row, column, var, inc = 0 , symbol;

	//USAGE
	if( argc<2 )
		{
			printf("USAGE: %s <height> ", argv[1]);
			exit(0);
		}


			//logic
			for( row = height ; row > 0 ; --row )
				{
					var = row;
					++inc;

						//number of spaces to be left
 						for( column = (var-1) ; column > 0  ; --column )
							{
								printf(" ");
							}

						//number of stars to be printed	
						for( symbol = ((2*inc) - 1) ; symbol > 0 ; --symbol )
							{
								printf("*");
							}		

					printf("\n");

				}

return 0;
}