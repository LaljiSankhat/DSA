#include <bits/stdc++.h>
using namespace std;


// leetcode 2302. Count Subarrays With Score Less Than K

long long countSubarrays(vector<int>& nums, long long k) {
    int n = nums.size();

    int l = 0, r = 0;
    long long ans = 0;
    int sum = 0;

    while(r < n){
        sum += nums[r];
        while(sum * (r - l + 1) >= k){
            sum -= nums[l];
            l++;
        }
        ans += (r - l + 1);
        r++;
    }

    return ans;
}


int main(){
    vector<int> nums = {2,1,4,3,5};
    int k = 10;
    cout << countSubarrays(nums, k) << endl;
    return 0;
}