#include<bits/stdc++.h>
using std::vector;

/*
Sorting with Comparator
    Given an integer vector and a bool variable flag, your task is
    to sort the vector in accordance to the boolean value. If the 
    bool value passed is true then sort it in non-decreasing order
    or vice versa.
    You can use any sorting technique of your choice.

Input Format
In the function an integer vector and a boolean is passed.

Output Format - Return an integer vector.
Sample Input  - {111, 33, 5, 7, 29}, flag = 1
Sample Output - {5, 7, 29, 33, 111}
*/
vector<int> sortingWithComparator(vector<int> a, bool flag){
    std::sort(a.begin(), a.end(), [flag](int a, int b){
        return flag ? a < b: a > b;
    });
    return a;
}