//	Program to multiply two matrices

#include<iostream>
using namespace std;
int main()
{
 int arr1[30][30],arr2[30][30],result[30][30];
 int row1,column1,row2,column2;
 int r1,c1,r2,c2,sum;
 int i,j;
	
	cout<<"enter the rows and columns of the first matrix : \n";
	cin>>row1>>column1;
	cout<<"enter the rows and columns of the second matrix : \n";
	cin>>row2>>column2;
	cout<<"\n\n";

if( column1==row2 )
{		
/*************************************************************
**	next wo loops to take input of matrix from the user 	**
*************************************************************/
// this is first matrix
		for(int i=0 ; i<row1 ; ++i )						//row number
		{
			for(int j=0 ; j<column1 ; ++j)					//column number
			{
				cout<<"enter the ["<<i<<","<<j<<"]th element of matrix1 : ";
				cin>>arr1[i][j];
			}	
		}	
cout<<"\n\n";
// this is second matrix
		for(int i=0 ; i<row2 ; ++i )						//row number
		{
			for(int j=0 ; j<column2 ; ++j)					//column number
			{
				cout<<"enter the ["<<i<<","<<j<<"]th element of matrix2 : ";
				cin>>arr2[i][j];
			}	
		}
cout<<"\n";		

/**************************************************************************************
***		making three loops , row2 and column1 are altering faster than column2      ***
***		and furthur by row1 (slowest altering and therefore the outermost loop)     ***
***		here resultant matrix will be of order row1 x column2 (i and j 				***
***		respectively) .!! here value of sum is to be made zero eveytime a new 		***
***		addition is to be performed ,so that it does not add in previous value		***
***************************************************************************************/


	for( r1=0,i=0 ; r1<row1,i<row1 ; ++r1,++i )									         	//to alter row1
	{
		for( c2=0,j=0 ; c2<column2,j<column2 ; ++c2,++j )									//to alter column2
		{
		sum=0;																				//impo statement !!	
			for( r2=0,c1=0 ; r2<row2 ,c1<column1 ; ++r2 ,++c1 )		 						//to alter row2 and column1
			{
				sum = sum + arr1[r1][c1]*arr2[r2][c2]; 
			}
			result[i][j]=sum;														        //stores the multiplied value in the resultant matrix
		}														
	}

// next loop is to output the resultant matrix
cout<<"On multiplying matrix 1 and 2 we get the result : \n\n\n";

	for( int p=0 ; p<row1 ; ++p )
	{
		for( int q=0 ; q<column2 ; ++q )
		{
			cout<<"\t\t"<<result[p][q];
		}
	cout<<"\n";	
	}
}

else
	cout<<"Sorry , Matrices cannot be multiplied : column1 and row2 does not match !!\n\n";
return 0;

}
