#include <bits/stdc++.h>
using namespace std;


// leetcode 2537. Count the Number of Good Subarrays

bool isValid(unordered_map<int, int> &mp, int k){
    int cnt = 0;
    for(auto it : mp){
        if(it.second > 1){
            cnt += (it.second * (it.second - 1)) / 2;
        }
    }
    return cnt >= k;
}

long long countGood(vector<int> &nums, int k){
    int n = nums.size();
    unordered_map<int, int> freq;
    long long ans = 0;
    long long pairs = 0;

    int l = 0, r = 0;

    while(r < n){
        freq[nums[r]]++;
        pairs += freq[nums[r]] - 1; 
        while(l <= r && pairs >= k){
            ans += (n - r);
            freq[nums[l]]--;
            pairs -= freq[nums[l]]; 
            if(freq[nums[l]] == 0){
                freq.erase(nums[l]);
            }
            l++;
        }
        r++;
    }

    return ans;
}

int main(){
    vector<int> nums = {3,1,4,3,2,2,4};
    int k = 2;
    cout << countGood(nums, k) << endl; 
    return 0;
}