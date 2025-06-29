#include <bits/stdc++.h>
using namespace std;


// leetcode 1498. Number of Subsequences That Satisfy the Given Sum Condition

int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int mod = 1e9 + 7;
    int n = nums.size();
    
    // Precompute powers of 2 up to n
    vector<int> pow2(n, 1);
    for(int i = 1; i < n; ++i)
        pow2[i] = (pow2[i - 1] * 2) % mod;
    
    int left = 0, right = n - 1;
    int count = 0;
    
    while(left <= right) {
        if(nums[left] + nums[right] <= target) {
            count = (count + pow2[right - left]) % mod;
            ++left;
        } else {
            --right;
        }
    }
    
    return count;
}


int main(){
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << numSubseq(nums, target) << endl;
    return 0;
}