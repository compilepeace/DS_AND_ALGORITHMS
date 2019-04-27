//the abs(var) returns the absolute value of 'var', i.e. without sign 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, d;
    int array[100000];
    int new_array[100000];
    unsigned int x;
    int index;
    
        scanf("%d %d", &n, &d);
    
        //taking input
        for(int i=0 ; i<n ; ++i)
        {
            cin>>array[i];   
        }
        
    
        //limiting number of left rotations between 0 to n(number of elements)
        if( d > n )
        {
            //if rotations are more than no. of elements
            //then rotations = remainder when divided by no. of elements
            d = d % n;
        }    
        
            
            //rotating array
            for(int j=0; j<n; ++j)
            {
                index = j - d;
                
                    if(index < 0)
                    {
                        //index is negative
                        index = n + index;
                        new_array[index] = array[j];   
                    }
                
                    else
                    {
                        //index is positive
                        new_array[index] = array[j];
                    }
            }
    
        
                    //print new_array
                    for(int z=0 ; z<n ; ++z)
                    {
                        cout<<new_array[z];
                        cout<<" ";
                    }
        
    
    
    return 0;
}
