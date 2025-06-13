#include <bits/stdc++.h>
using namespace std;


// leetcode 2616. Minimize the Maximum Difference of Pairs

bool isPossible(vector<int> &nums, int p, int mid){
    // int n = nums.size();
    // int maxi = 0;

    // // start with 0th index
    // for(int i = 0; i < n - 1 && p > 0; i = i + 2){
    //     maxi = max(maxi, abs(nums[i] - nums[i + 1]));
    //     p--;
    // }

    // // start with 1st index
    // int maxi2 = 0;
    // for(int i = 1; i < n - 1 && p > 0; i = i + 2){
    //     maxi2 = max(maxi2, abs(nums[i] - nums[i + 1]));
    //     p--;
    // }

    // return min(maxi, maxi2) <= mid;

    int cnt = 0;
    int i = 0;

    while (i < nums.size() - 1) {
        if (abs(nums[i] - nums[i + 1]) <= mid) {
            cnt++;
            i += 2; // Skip next index as it’s already used
        } else {
            i += 1;
        }

        if (cnt >= p) return true; // early stop if we already have enough pairs
    }

    return cnt >= p;
}

int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int l = 0, r = nums[n - 1] - nums[0];
    int ans = -1e9;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(isPossible(nums, p, mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}


int main(){
    vector<int> nums = {10,1,2,7,1,3};
    int p = 2;
    cout << minimizeMax(nums, p) << endl;
    return 0;
}