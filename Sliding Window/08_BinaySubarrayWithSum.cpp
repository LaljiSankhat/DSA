#include <bits/stdc++.h>
using namespace std;


/*
    930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
["1,0,1",0,1]
["1,0,1,0",1]
[1,"0,1,0,1"]
[1,0,"1,0,1"]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
*/

// to find sum == k we found as 
// noOfSubarray(sum <= k) - noOfSubarray(sum < k) = noOfSubarray(sum == k)

int findSubarrayWithSumLessThanGoal(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int l = 0, r = 0, sum = 0, cnt = 0;

    while(r < n){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int countBinarySubarrayWithSum(vector<int> &nums, int goal){
    int sumLessGoal = findSubarrayWithSumLessThanGoal(nums, goal);
    int sumLessGoalMinusOne = findSubarrayWithSumLessThanGoal(nums, goal - 1);

    return sumLessGoal - sumLessGoalMinusOne;
}


int main(){
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout << countBinarySubarrayWithSum(nums, goal);
    return 0;
}