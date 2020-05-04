#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int height = atoi(argv[1]);
	int row, row_, space_, space, var, var_, inc = 0 , symbol, symbol_, iter_ = 0 ;

	//USAGE
	if( argc<2 )
		{
			printf("USAGE: %s <height> ", argv[1]);
			exit(0);
		}

	//USAGE	
	if( (height % 2) == 0)
		{
			printf("USAGE: Height of diamond should be an odd number\n");
			exit(0);
		}	

		//Height should be odd number
		else
			{	
				//star patten logic  
				for( row = ((height/2) + 1) ; row > 0 ; --row )
					{
						var = row;
						++inc;

							//number of spaces to be left
 							for( space = (var-1) ; space > 0  ; --space )
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

				//reverse star
				//iterate rows	
				for( row_ = height/2 ; row_ > 0 ; --row_ )	
					{
						var_ = row_;
						++iter_;
							//iterate space
							for( space_ = 0 ; space_ < iter_ ; ++space_ )
								{
									printf(" ");
								}
							

							//iterate stars
							for( symbol_ = ((2*var_) - 1) ; symbol_ > 0 ; --symbol_ )
								{
									printf("*");
								}
						
						printf("\n");	
					}
			}
return 0;
}