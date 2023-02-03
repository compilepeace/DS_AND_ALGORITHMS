#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int min_diff = 0x7fffffff;      // value of INT_MAX
    pair<int, int> cs;
    
    /*
    // DEBUG
    for (auto x: arr)
        cout << x << " ";
    cout << "\nx: " << x << "\n";
    */

    // create pairs
    for (auto i = 0; i < arr.size(); ++i){
        for (auto j = i+1; j < arr.size(); ++j){
            int sum = arr[i] + arr[j];
            cout << "min_diff: " << min_diff << "\n";
            if (abs(x - sum) < min_diff){
                min_diff = abs(x - sum);
                cs = make_pair(arr[i], arr[j]);
            }
        }
    }
    return cs;
}