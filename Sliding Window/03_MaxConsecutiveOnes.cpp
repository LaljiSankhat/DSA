#include <bits/stdc++.h>
using namespace std;


/*
    1004. Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the 
array if you can flip at most k 0's. 

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

// we can reformat question as find max length subarray with exact k zeros 
// after we can replace that zeros with one and we can find the max subarray with replacing 0 to 1

int maxConsecutiveOnes(vector<int> &nums, int k){
    int n = nums.size();
    
    int l = 0, r = 0, maxLen = 0;
    int zeros = 0;

    while(r < n){
        if(nums[r] == 0) zeros++;
        if(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }

    return maxLen;
}


int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2; 

    cout << maxConsecutiveOnes(nums, k);
    return 0;
}