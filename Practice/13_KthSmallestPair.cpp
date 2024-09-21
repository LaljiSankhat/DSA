#include <bits/stdc++.h>
using namespace std;


/*
    719. Find K-th Smallest Pair Distance
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs 
nums[i] and nums[j] where 0 <= i < j < nums.length. 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2
*/

// this will give TLE
int KthSmallestPair(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> diff;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            diff.push_back(abs(nums[i] - nums[j]));
        }
    }

    sort(diff.begin(), diff.end());

    return diff[k - 1];
}


bool helper(int mid, vector<int>& nums, int k){
    int n = nums.size();
    int j = 1;
    int total = 0;
    for(int i = 0; i < n; i++){
        while(j < n && nums[j] - nums[i] <= mid) j++;
        j--;
        int x = j - i;
        total += x;
    }
    return total >= k;
}

int kthPair(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxDiff = nums[n - 1] - nums[0];
    int l = 0, r = maxDiff;
    while(l < r){
        int mid = l + (r - l)/2;
        if(helper(mid, nums, k)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
} 


int main(){
    vector<int> nums = {1, 6, 1};
    int k = 3;
    // cout << KthSmallestPair(nums, k);
    cout << kthPair(nums, k);
    return 0;
}

