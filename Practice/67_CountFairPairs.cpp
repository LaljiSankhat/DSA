#include <bits/stdc++.h>
using namespace std;


// leetcode 2563. Count the Number of Fair Pairs


long long countFairPairs(vector<int> &nums, int lower, int upper){
    long long ans = 0;
    int n = nums.size();


    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
        int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
        ans += (r - l);
    }

    return ans;
}


// method 2 
// TLE
long long countLess(vector<int> &nums, int target){
    // if(target <= 0) return 0;
    long long ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(i != j && nums[i] + nums[j] <= target){
                ans++;
            } else if(i != j && nums[i] + nums[j] >= target){
                break;
            }
        }
    }

    return ans;
}

long long count(vector<int> &nums, int lower, int upper){
    long long ans = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    ans += countLess(nums, upper) - countLess(nums, lower - 1);
    return ans;
}

int main(){
    vector<int> nums = {-1, 0};
    int lower = 1, upper = 1;
    cout << countFairPairs(nums, lower, upper) << endl; // 6
    cout << count(nums, lower, upper) << endl; // 6
    return 0;
}