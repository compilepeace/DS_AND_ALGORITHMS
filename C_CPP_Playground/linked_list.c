/*****************************************************************************************************************
****************************** Program to implement  ||| LINKED LIST |||  :  *************************************
****************************** contains functions for : Searching , deleting *************************************	
******************************                                               *************************************
*****************************************************************************************************************/	

#include<stdio.h>
#include<stdlib.h>

struct node *first ;							//**GLOBAL VARIABLE Pointer- that always points to first node of the list****



struct node
{
	int value;
	struct node *next;
};

/**************************
**** This function creates a node using malloc()  , *******
**** function returns the address ( of the newly    *******
**** allocated node ) to first ( pointer )          *******
****												  *******
**************************/

	struct node *create_node( struct node *address_first , int val)
	{	
		struct node *new_node ;

		new_node = malloc(sizeof(struct node));							// allocating memory (not initialised)
			if( new_node == NULL )										// if malloc() fails to allocate memory
			{
				printf("Failed to allocate memory !!");
				exit(0);													// same as exit(EXIT_FAILURE)
			}

		(*new_node).value = val ;										// storing value in node : same as new_node->value
	
			new_node->next = address_first ;

		return new_node ;			
	}

/**************************
***** This fuction is used to store data in the list ******
***** until the user enters '0' and each time it     ******
***** takes i/o from the user it calls a function    ******
***** to create node . when 0 is given as i/o ,      ******
***** function returns pointer to the first node     ******
***** of the list .									 ******
**************************/


struct node *read_val(void)
{	
	int val;

	printf("Enter the values to be entered in list :(press 0 to end) ");
	for(;;)
	{	
		scanf("%d",&val);
		if( val == 0 )			
			return first ;

		first = create_node( first , val );							//  val is value to be entered in list in reverse order
	}	

}

/**************************
***** This fuction searches the list from starting ******
***** (first pointer) of the list . returns pointer******
***** to the position where the value was found    ******
*****											   ******
**************************/

	struct node *search_val( struct node *first , int val_search )
	{
		struct node *temp_address;
			for( temp_address = first ; temp_address != NULL ; temp_address = first->next)
			{
				if( first->value == val_search )
					{
						printf("%d found \n", val_search );
						return temp_address ;
					}	
				else
					printf("Value Not Found !\n");
			}	
	}

/***************************
**** this function uses the trailing pointer technique *****
**** two pointers of "sruct node type" - cur (current) *****
**** and prev (previous). when cur finds the value to  *****
**** be deleted ,free() is called and prev then points *****
**** cur->next or (*cur).next 						   *****
*************************/
 

struct node *delete_node( struct node *first , int value )
{	
	struct node *cur , *prev ;

		for( cur = first , prev = NULL ;
			 cur != NULL && cur->value != value ;
			 prev = cur , cur = cur->next );

			if( prev == NULL )
			  	first = first->next;
			
			if( cur == NULL )
				return first ;
			
			else
				prev->next = cur->next ;

			free(cur);			

	return first;	
}

/*************************
**** Function to display node :	ptr is a temporary  ******
**** pointer , but the probleum is that list is 	******
**** stored in reverse in order of the list entered ******
**** by the user. 									******
*************************/
struct node *display_node(struct node *ptr)
{	
	int i=0 , count = 0 ;
	printf("contents of the node are : \n");
	
	do
	{													// To find length of the list so that an array of the same length 
														// can be created and elements of list can be stored in it
		ptr = ptr->next ;
		count = count + 1 ; 

	}while( ptr->next != NULL );
		
	int arr[count];
		do
		{												// values are being stored in an array
			arr[i] = ptr->value ;
			i = i + 1 ;
			ptr = ptr->next ;

		}while( ptr->next != NULL );	

			for( i = count ; i >= 0 ; --i)				// prints the array from the last element
			{
				printf("%d\n" , arr[i] );
			}
}



int main()
{
	first = NULL;
	struct node *val_found ;
	int value , choice ;

	first = read_val();

	printf("Enter the choice : \n");
	printf("1. Searching \n");
	printf("2. Deleting \n");
	scanf("%d",&choice);

			switch(choice)
			{
				case 1 : printf("Enter the value to be searched :\n" );
						 scanf("%d", &value) ;
							val_found = search_val( first , value );
							display_node(first);
						 break;			
				
				case 2 : printf("Enter the value to be deleted :\n");
						 scanf("%d", &value);
						 	first = delete_node( first , value ) ;
						 	display_node(first);
						 break; 
			};
			
return 0;
}
