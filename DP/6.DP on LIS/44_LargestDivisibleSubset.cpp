#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode : 368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that 
every pair (answer[i], answer[j]) of elements in this subset satisfies:
Condition for Divisible Subset : 
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them. 

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8] 

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

/* 
    to solve : 
    first we sort the array 
    then we find Longest Divisilbe Subsequence instead of LIS so we need to change only one
    condition increasing to divisible.
*/

// from Q.42
vector<int> printLIS(int n, vector<int> &nums){
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int lastIndex = 0;

    sort(nums.begin(), nums.end());

    for(int i = 1; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){ // this is valid, this can be part of LIS
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    int ind = 1;
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());

    return lis;
}


int main(){
    vector<int> nums = {1,7,4,8,16};
    int n = nums.size();
    vector<int> lis = printLIS(n, nums);
    for(auto a : lis) cout << a << " ";
    return 0;
}