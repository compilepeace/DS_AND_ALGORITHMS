#include<stdio.h>
int main(void)
{  int n;
	printf("enter the amount : ");
	scanf("%d",&n);
	if(n/20==0)
	{printf("no, of 20 rupees notes = %d",n/20);
	}
	else
	{
		if((n%20)%10==0)
		{printf("no. of 20rs notes and 10rs notes are  respectively %d %d",n/20,(n%20)/10);
		}
			else
			{
				if(((n%20)%10)%5==0)
				printf("the no, of 20,10,5 rupee notes are respectively : %d %d %d",n/20,(n%20)/10,((n%20)%10)/5);
			
					else{
						printf("the no, of 20,10,5,1 rupee notes are respectively %d %d %d %d: ",n/20,(n%20)/10,((n%20)%10)/5,(((n%20)%10)%5/1));
					}
				

		    }
	}
	return 0;
}

