#include <bits/stdc++.h>
using namespace std;


/*
    673. Number of Longest Increasing Subsequence
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing. 

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
 
Constraints:
1 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/

/*
    To solve this question we have to keep a count array which will count the nuber of LIS
    initially all counts will be one because of it's number itself
    if LIS then we copy the count of prev
    if dp[pre] + 1 == dp[cur] then we got same length so we add prev count to current count
*/
// Here we are modify the tabulation code of LIS

int noOfLIS(vector<int> &nums){
    int n = nums.size();

    vector<int> dp(n, 1), count(n, 1);
    int maxi = 0;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]){ // this is valid, this can be part of LIS
                dp[i] = dp[prev] + 1;
                count[i] = count[prev];
            } else if(nums[prev] < nums[i] && dp[prev] + 1 == dp[i]){
                count[i] += count[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int numbers = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi) numbers += count[i];
    }
    return numbers;
}


int main(){
    vector<int> nums = {1,7,4,8,16};
    cout << noOfLIS(nums) << endl;
    return 0;
}