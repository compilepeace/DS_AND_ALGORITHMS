#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int arr_i, arr_j, sum=0 , var1 , var2, var=0 ;
    int arr_k, arr_l;                       //remove
    int array_sum[16], z, y, row, column, largest, lar;

    int arr[6][6];
    
    //input
    for(arr_i = 0; arr_i < 6; arr_i++)
    {
        for(arr_j = 0; arr_j < 6; arr_j++)
            scanf("%d",&arr[arr_i][arr_j]);           
      
    }
   

   for(arr_k=0; arr_k<6 ; arr_k++)
    {
        printf("\n\n");
            
            for(arr_l=0 ; arr_l<6 ; arr_l++)
                printf("%d\t", arr[arr_k][arr_l]);           
      
    }




    //code

    //
    for(row=0 ; row<4 ; ++row)
        {

            for(column=0 ; column<4 ; ++column)
                {    
                    //add sum of pattern hourglass
                    for(var1 = row, z=0 ; var1<(row + 3) ; ++var1, ++z)
                        {

                            for(var2 = column, y=0 ; var2<(column + 3) ; ++var2, ++y)
                                {
                                    if( z == 1 )
                                        {
                                            if(y == 1)
                                                {
                                                    sum = sum + arr[var1][var2];
                                                   // printf("\n**sum: [%d][%d], y = %d\n ", var1, var2, y);
                                                }
                                            //else
                                              //  printf("NOP");                   
                                        }

                                    else
                                        {
                                            sum = sum + arr[var1][var2];
                                           // printf("\n##sum: [%d][%d] \n", var1, var2);
                                        }    
                                }            
                        }
                //store sum in array_sum;
                array_sum[var] = sum ;
                ++var;    
                //printf("\n\nsum[%d] = %d\n\n", var, sum);
                sum = 0;        

                }
        }


    largest = array_sum[0];
        
    //find largest number
    for(lar=0 ; lar<16 ; ++lar)
    {
        if(array_sum[lar] > largest)
            largest = array_sum[lar];
        else;
    }    

printf("\n\nlargest hourglass sum in 2-D array : %d\n\n", largest);
    return 0;
}
