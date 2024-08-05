#include <bits/stdc++.h>
using namespace std;

/*
    300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing 
subsequence. 

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

/* we have to select in increasing order */ 
/* to solve this we have add a condition of increasing element */
/* we take a prevIndex in function to check weather next elem is sutable or not*/

int longestIncreasingSubsequence(int i, int pi, vector<int> &nums){
    if(i == nums.size()) return 0;

    // if not take then move to next index
    int notTake = longestIncreasingSubsequence(i + 1, pi, nums);
    // if take
    int take = INT_MIN;
    if(pi == -1 || nums[pi] < nums[i]) take = 1 + longestIncreasingSubsequence(i + 1, i, nums);

    return max(take, notTake);
}

// memoization
int longestIncreasingSubsequenceDp(int i, int pi, vector<int> &nums, vector<vector<int>> &dp){
    if(i == nums.size()) return 0;
    if(dp[i][pi + 1] != -1) return dp[i][pi + 1];


    // if not take then move to next index
    int notTake = 0 + longestIncreasingSubsequenceDp(i + 1, pi, nums, dp);
    // if take
    int take = 0;
    if(pi == -1 || nums[pi] < nums[i]) take = 1 + longestIncreasingSubsequenceDp(i + 1, i, nums, dp);

    return dp[i][pi + 1] = max(take, notTake);
}


int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << longestIncreasingSubsequence(0, -1, nums) << endl;
    cout << longestIncreasingSubsequenceDp(0, -1, nums, dp) << endl;
    return 0;
}