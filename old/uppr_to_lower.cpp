//5. change the case of alphabets

#include<stdio.h>
int main()
{
	char alphabet,newchar;
	
	printf("enter the alphabet : ",alphabet);
	scanf("%c",&alphabet);
	
		if(alphabet>=65 && alphabet<=91)
		{
			newchar = alphabet + 32;
			printf("the equivalent uppercase is : %c ", newchar);
	    }
		
		else if(alphabet>=97)
		{
			newchar = alphabet - 32;
			printf("the equivalent lowercase is : %c ", newchar);
        }
return 0;			
}
