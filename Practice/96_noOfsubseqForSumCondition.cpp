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

int method2(vector<int>& nums, int target){
    int n = nums.size();

    vector<pair<int, int>> numToIndex;
    for(int i = 0; i < n; i++){
        numToIndex.push_back({nums[i], i});
    }

    sort(numToIndex.begin(), numToIndex.end(), [](pair<int, int> &a, pair<int, int> &b){
        return b.first > a.first;
    });

    // for(int i = 0; i < n; i++){
    //     cout << "{" << numToIndex[i].first << " " << numToIndex[i].second << "} ";
    // }
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j){
        if(numToIndex[i].first + numToIndex[j].first <= target){
            ans += 1 << (abs(numToIndex[i].second - numToIndex[j].second) - 1);
            i++;
        } else {
            j--;
        }
    }
    if(2 * numToIndex[i].first <= target) ans += 1;
    return ans;
}


int main(){
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << numSubseq(nums, target) << endl;
    cout << method2(nums, target) << endl;
    return 0;
}