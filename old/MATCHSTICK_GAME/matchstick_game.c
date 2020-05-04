/* 

Abhinav Thakur
compilepeace@gmail.com


Description - 21 matchsticks are there, user goes first , 
	      game such that both user and computer has to 
	      pick up matchsticks in range (1 to 4) such
	      that when 1 matchstick is left the user looses
*/					   					 


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int nom = 21;		//no. of matchsticks
	int user_ip;

	
		printf("-=-=-=-=-=-=-=-=- Welcome to the Matchstick game -=-=-=-=-=-=-=-=-\n\n");
		printf("There are 21 matchsticks in total to be picked up turn-wise. You\n");
		printf("will be competing with a dumb machine,so just believe in youself.\n");
		printf("The one left with one matchstick at last will loose the game. You\n");
		printf("can pick up only [1/2/3/4] matchsticks at a time.\n");	
		printf("User goes first !\n\n");
			
			
			// an infinite loop
			for(;;)
			{
				printf("\n(U)Pick up matchstick(s) : ");
				scanf("%d", &user_ip);
				
					
					// User's turn block
					if( user_ip<1 || user_ip>4 )
					{
						printf("Please enter valid number !!\n");
						continue;	
					}				
						// updating number of matchsticks left
						nom -= user_ip;
						printf("\t(U)Picked matchstick(s) = %d \n\tleft = %d\n", user_ip, nom);
							// termination condition
							if (nom == 1)
							{
								printf("left free, computer looses !!");
								exit(0);
							}
					
				
				
						// Computer's turn block
						nom = nom -(5-user_ip);
						printf("\t(C)Picked matchstick(s) = %d \n\tleft = %d\n", 5-user_ip, nom);
							// termination condition
							if (nom == 1)
							{
								printf("You loose, better luck next time..\n");
								exit(0);
							}
										
		}
			
}
