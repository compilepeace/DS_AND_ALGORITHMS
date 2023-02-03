/*
K-Rotate
Given an integer vector and a value k, your task is to rotate the array k times clockwise.

Input Format  - In the function an integer vector and number k is passed.
Output Format - Return an integer vector.

Sample Input  {1, 3, 5, 7, 9}, x = 2
Sample Output {7, 9, 1, 3, 5}

Explanation
After 1st rotation - {9, 1, 3, 5, 7}
After 2nd rotation - {7, 9, 1, 3, 5}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    // rotate the vector clockwise (k times)
    for (int i = 0; i < k; ++i){
        int last_element = a.back();
        a.pop_back();
        a.insert(a.begin(), last_element);
    }
    
    return a;
}