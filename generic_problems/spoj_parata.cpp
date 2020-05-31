/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.

Input:

3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
12
36
1

*/


#include <iostream>
#include <algorithm>
using namespace std;


// Paratas cooked by cook of rank 'r' in 'm' minutes
int paratasCooked(int r, int m)
{
    int count = 0;
    int i = 1;
    
    while ( true )
    {
       m = m - i*r;
       if ( m < 0 )
           return count;
       ++count;
       ++i;
    }
}


// Returns true if 'p' no. of paratas can be cooked in 'm' minutes by cooks of ranks[].
bool isParataPossible(int p, int r[], int n, int m)
{
    int sum = 0;

    // Iterate over cooks to calculate the sum of paratas that can be made in m minutes.
    for (int i = 0; i < n; ++i)
    {
        int x = paratasCooked(r[i], m);         // Number of paratas made by ith cook
        sum += x;
    }

    return (sum >= p) ? true: false;
}


int minutesForOrder(int p, int r[], int n)
{
    sort(r, r + n);     // Sorting cook ranks

    // Range of min/max minutes to make 10 paratas
    int s = 0;              
    int e = r[0] * ( p * (p+1) / 2);            // i.e. rank * n(n+1)/2 
    int result_minutes = 0;
    
    while ( s <= e )
    {
        int mid = (s + e)/2;                     
        bool status = isParataPossible(p, r, n, mid);   // Is 'p' parata possible in 'mid' minutes?
        
        if (status == true){
            result_minutes = mid;
            e = mid - 1;
        }

        else
            s = mid + 1;
    }

    return result_minutes;
}



int main()
{
    int t;
    cin >> t;


    for (int z = 0; z < t; ++z)
    {
        int p, l;
        cin >> p >> l;

        int ranks[l];

        for (int i = 0; i < l; ++i)
            cin >> ranks[i];

        // Finding minimum number of minutes to get P paratas ready.
        int result = minutesForOrder(p, ranks, l);
        cout << result << endl;
    }
}

