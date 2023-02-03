#include<bits/stdc++.h>
using std::vector;

/*
Chopsticks
Given N sticks and an array length where each length[i] represents length of each stick. Your task is to make maximum number of pairs of these sticks such that the difference between the length of two sticks is at most D. A stick can't be part of more than one pair of sticks.

Input Format  - In the function an integer vector length and number D is passed.
Output Format - Return an integer representing total number of such pairs.
Sample Input  - {1, 3, 3, 9, 4}, x = 2
Sample Output - 2

Explanation - (1st, 3rd) and (2nd, 5th) can be paired together.
*/
int pairSticks(vector<int> sticks, int D)
{
    if (sticks.size() < 2)
        return 0;

    // sort all chopsticks in ascending order : [1, 3, 3, 9, 4] -> [1, 3, 3, 4, 9]
    std::sort(sticks.begin(), sticks.end());
    
    // count appropriate chopstick pairs
    int ans = 0;
    for (int i = 0; i < sticks.size() - 1; ){
        if (std::abs(sticks[i] - sticks[i+1]) <= D){
            i += 2;
            ++ans;
        }
        else
            i += 1;
    }
    return ans;
}