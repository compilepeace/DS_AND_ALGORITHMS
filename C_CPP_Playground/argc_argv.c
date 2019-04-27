/*************************************************************************************
*** understanding argc and argv . First compile this program with the help of the  ***
*** command => 			gcc argc_argv.c -o nargc_argv 							   ***
*** here argc_argv is the name of the program , -o flag helps us to name           ***
*** executable file which will be named nargc_argv after executing this command    ***
*** to run this executable => 		./nargc_argv 								   ***
*** i.e. nargc_argv is the name of the executable file made by above command       ***
**************************************************************************************/

#include<stdio.h>

int main(int argc , char *argv[])
{
	int i,sum=0;

		printf("the number of arguments provided to the command line is : %d\n", argc);

	if(argc>1)
	{
		for(i=1 ; i<argc ; i++)
		{
			printf(" argv[%d] = %s\n",i,argv[i]);
			sum = sum + atoi(argv[i]);
		}
	printf("total = %d\n",sum);
    }

return 0;
}	
