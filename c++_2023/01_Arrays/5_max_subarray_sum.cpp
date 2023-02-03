#include <iostream>
using std::cout;

#define MAX_NEG 0X80000000

/*
    time complexity: O(n) - Kadane's Algorithm
    eg: input array = [-2, 3, 4, -1, 5, -12, 6, 1, 3]
        currSum     = [0, 3, 7, 6, 11, 0, 6, 7, 10] 
*/
int maxSubarraySum3 (int arr[], int size)
{
    int curr_sum = 0;
    int max_sum = 0x80000000;      // max negative value (MAX_NEG)

    for (int i = 0; i < size; ++i){
        // works for edge case too - [-2, -1, -3]
        curr_sum = (curr_sum + arr[i] < arr[i]) ? arr[i]: curr_sum + arr[i];
        max_sum = std::max(curr_sum, max_sum);
    }

    return max_sum;
}

/*
    time complexity: O(n^2) - prefix/cumulative-sum method
    create a cummulative sum array to find subarray sum between 
    i & j th array indices
    eg: input arr = [-2, 3, 4, -1, 5, -12, 6, 1, 3]
        prefix arr= [-2, 1, 5, 4, 9, -3, 3, 4, 7]  
*/
int maxSubarraySum2 (int arr[], int size)
{
    int max_sum = MAX_NEG;
    int prefix[size] = {0};

    // create a prefix array
    prefix[0] = arr[0];
    for (int i = 1; i < size; ++i){
        prefix[i] = arr[i] + prefix[i-1]; 
    }

    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            // find subarray sum using prefix array below formulae
            int curr_sum = (i > 0) ? prefix[j] - prefix[i-1] : prefix[j];
            max_sum = std::max(curr_sum, max_sum);
        }
    }
    return max_sum;
}

/*
    time complexity: O(n^3)
    brute-force method to find max subarray sum from input array
*/
int maxSubarraySum1 (int arr[], int size)
{
    int max_sum = MAX_NEG;
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            // compute sum of subarray
            int curr_sum = 0;
            for (int k = i; k <= j; ++k){
                curr_sum += arr[k];
            }
            // update max_sum
            max_sum = std::max(curr_sum, max_sum);
        }
    }
    return max_sum;
}

int main ()
{
    int array[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    //int array[] = {-2, -1, -3};          // edge-case : -1
    int size = sizeof(array)/sizeof(int);
    
    cout << "Maximum subarray sum O(n^3): " << maxSubarraySum1(array, size) << "\n";
    cout << "Maximum subarray sum O(n^2): " << maxSubarraySum2(array, size) << "\n";
    cout << "Maximum subarray sum O(n)  : " << maxSubarraySum3(array, size) << "\n";
    
    return 0;
}