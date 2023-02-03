#include<bits/stdc++.h>
using std::vector;
using std::pair;

/*
Sorting Cartesian Points
Given co-ordinates of N points on X-Y axis, your task is to sort them in accordance to the
x-coordinate. If the x-coordinates are same then compare y-coordinates.

Input Format - In the function an integer vector of pairs is passed.
Output Format - Return the vector in sorted order.
Sample Input - { (3, 4), (2, 3), (3, 7), (1, 5), (3, 4) } 
Sample Output -{ (1, 5), (2, 3), (3, 4), (3, 4), (3, 7) } 
*/
vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    // Arrange all points (pair of x & y coordinate) in ascending order w.r.t x coordinate
    // if x coordinate of 2 points are same, comparison is made based on y coordinates;
    std::sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int,int> p2){
        return (p1.first == p2.first) ? (p1.second < p2.second) : (p1.first < p2.first);
    });
    return v;
}