#include <bits/stdc++.h>
using namespace std;


// leetcode 2799. Count Complete Subarrays in an Array

int helper(vector<int> &nums, int distinct){
    if(distinct == 0) return 0; 
    int l = 0, r = 0;
    unordered_map<int, int> mp;
    int count = 0;
    int n = nums.size();

    while(r < n){
        mp[nums[r]]++;
        while((l <= r && mp.size() > distinct)){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0){
                mp.erase(nums[l]);
            }
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    int distinct = 0;
    set<int> st;
    for(auto num : nums){
        st.insert(num);
    }
    distinct = st.size();
    cout << distinct << endl;

    return helper(nums, distinct) - helper(nums, distinct - 1);
    
}


int main(){
    vector<int> nums = {1,3,1,2,2};
    cout << countCompleteSubarrays(nums) << endl;
    return 0;
}