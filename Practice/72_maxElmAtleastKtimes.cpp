#include <bits/stdc++.h>
using namespace std;


// leetcode 2962. Count Subarrays Where Max Element Appears at Least K Times

long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    int l = 0, r = 0;
    int freq = 0;
    long long ans = 0;
    int m = 0;

    for(int num : nums){
        m = max(m, num);
    }

    while(r < n){
        if(nums[r] == m) freq++;

        while(l <= r && freq >= k){
            ans += (long long)(n - r);
            if(nums[l] == m){
                freq--;
            }
            l++;
        }
        r++;
    }

    return ans;
}


int main(){
    vector<int> nums = {1,4,2,1};
    int k = 3;
    cout << countSubarrays(nums, k) << endl;
    return 0;
}