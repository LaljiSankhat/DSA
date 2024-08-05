#include <bits/stdc++.h>
using namespace std;


/*
 Leetcode : 2035. Partition Array Into Two Arrays to Minimize Sum Difference

You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays 
of length n to minimize the absolute difference of the sums of the arrays. To partition nums,
put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

Example 1:

example-1
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

Example 2:

Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

Example 3:

example-3
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

*/

/*
Here we use concept of Q.14 subsetsum  where in tabulation we full dp array. in dp array we can say that
dp[i][j] indicates that we can achieve target = j till ith index.
*/


// Tabulation
bool subsetSumTab(int target, vector<int> &arr, vector<vector<bool>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = true;
    if(arr[0] <= target) dp[0][arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool notTake = dp[i - 1][k];
            bool take = false;
            if (k >= arr[i])
                take = dp[i - 1][k - arr[i]];
            dp[i][k] = take || notTake;
        }
    }
    return dp[arr.size() - 1][target];
}

int minDiff(vector<int> &arr){
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, 0));
    subsetSumTab(totalSum,arr,dp);


    int mini = 1e9;
    for(int s1 = 0; s1 <= totalSum / 2; s1++){
        if(dp[n - 1][s1]){
            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }
    return mini;
}

// we can use space optimised solution becausewe only need of last row of dp table lets do it 

// space optimization
bool subsetSumSpace(int target, vector<int> &arr, vector<bool> &prev){
    vector<bool>  cur(target + 1, 0);
    prev[0] = cur[0] = true;
    if(arr[0] <= target) prev[arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool notTake = prev[k];
            bool take = false;
            if (k >= arr[i])
                take = prev[k - arr[i]];
            cur[k] = take || notTake;
        }
        prev = cur;
    }
    return prev[target];
}

int minDiffSpace(vector<int> &arr){
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];

    int k = totalSum;
    vector<bool> prev(k + 1, 0);
    subsetSumSpace(k, arr, prev);


    int mini = 1e9;
    for(int s1 = 0; s1 <= totalSum / 2; s1++){
        if(prev[s1] == true){
            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }
    return mini;
}

int main(){
    vector<int> arr = {3,9,7,3};
    cout << minDiff(arr) << endl;
    cout << minDiffSpace(arr) << endl;
    return 0;
}