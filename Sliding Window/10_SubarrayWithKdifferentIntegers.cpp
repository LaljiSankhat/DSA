#include <bits/stdc++.h>
using namespace std;


// leetcode 992. Subarrays with K Different Integers


/*

    Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]


*/

int subarrayLessThanK(vector<int> &nums, int k){
    int n = nums.size();
    int l = 0, r = 0;
    unordered_map<int, int> freq;

    int ans = 0;

    while(r < n){
        freq[nums[r]]++;
        while(!freq.empty() && freq.size() > k){
            freq[nums[l]]--;
            if(freq[nums[l]] == 0){
                freq.erase(nums[l]);
            }
            l++;
        }
        ans += (r - l) + 1;
        r++;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarrayLessThanK(nums, k) - subarrayLessThanK(nums, k - 1);
}

int main(){
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}