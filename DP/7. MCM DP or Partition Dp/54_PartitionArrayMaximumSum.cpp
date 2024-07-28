#include <bits/stdc++.h>
using namespace std;


/*
    1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer
fits in a 32-bit integer. 

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1

Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/

/*
    Here we will be given an array and also a k value is given, k value will tell max partition length
    we have to do first partitions with max size of partition is k, then we change all values of that partition by the
    max value of that partition and then we have to add all values of all partition and maximize it...
*/

/*
    to solve this we will use front partition method 
    here f(ind) will tell the maximum sum of array start from ind to end ind of array
*/


int maxSumAfterPartitionArray(int i, vector<int> &arr, int k){
    int n = arr.size();
    if(i == n) return 0;

    // try all partitions
    int maxValue = -1e9;
    int maxi = -1e9;
    int len = 0;
    for(int j = i; j < min(n, i + k); j++){
        len++;
        maxValue = max(maxValue, arr[j]);
        int ans = (len * maxValue) + maxSumAfterPartitionArray(j + 1, arr, k);
        maxi = max(maxi, ans);
    }

    return maxi;
}

// Memoization
int maxSumAfterPartitionArrayDp(int i, vector<int> &arr, int k, vector<int> &dp){
    int n = arr.size();
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    // try all partitions
    int maxValue = -1e9;
    int maxi = -1e9;
    int len = 0;
    for(int j = i; j < min(n, i + k); j++){
        len++;
        maxValue = max(maxValue, arr[j]);
        int ans = (len * maxValue) + maxSumAfterPartitionArrayDp(j + 1, arr, k, dp);
        maxi = max(maxi, ans);
    }

    return dp[i] = maxi;
}


// Tabulation
int maxSumAfterPartitionArrayTab(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int maxValue = -1e9;
        int maxi = -1e9;
        int len = 0;
        for (int j = i; j < min(n, i + k); j++){
            len++;
            maxValue = max(maxValue, arr[j]);
            int ans = (len * maxValue) + dp[j + 1];
            maxi = max(maxi, ans);
        }

        dp[i] = maxi;
    }

    return dp[0];    
}


int main(){
    vector<int> arr = {1,4,1,5,7,3,6,1,9,9,3};
    int k = 4;
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << "Hello" << endl;
    cout << maxSumAfterPartitionArray(0, arr, k) << endl;
    cout << maxSumAfterPartitionArrayDp(0, arr, k, dp) << endl;
    cout << maxSumAfterPartitionArrayTab(arr, k) << endl;
    return 0;
}