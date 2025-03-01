#include <bits/stdc++.h>
using namespace std;


// leetcode 42. Trapping Rain Water

// for index i 
// water = min(leftmax, rightmax) - arr[i] 
// and then we add all

int trapingRainWater(vector<int> &nums){
    int n = nums.size();
    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);
    prefixMax[0] = nums[0];
    suffixMax[n - 1] = nums[n - 1];

    for(int i = 1; i < n; i++){
        prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        suffixMax[n - i - 1] = max(suffixMax[n - i], nums[n - i - 1]);
    }
    
    int totalWater = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] < prefixMax[i] && nums[i] < suffixMax[i]){
            totalWater += min(prefixMax[i], suffixMax[i]) - nums[i];
        }
    }
    return totalWater;
}


// now optimization with space, we are using O(n) space we have to optimise

// to do this we are doing two way traversal e.g. left and right 
// if left < right than we say there can be water between left and right because left < right 
// but leftmax of left is 0 then water will not stay on top of left and same process when right < left

int trap(vector<int> &nums){
    int n = nums.size();
    int leftMax = 0, rightMax = 0, l = 0, r = n - 1;
    int totalWater = 0;

    while(l < r){
        if(nums[l] <= nums[r]){
            if(leftMax > nums[l]){
                totalWater += leftMax - nums[l];
            } else {
                leftMax = nums[l];
            }
            l++;
        } else {
            if(rightMax > nums[r]){
                totalWater += rightMax - nums[r];
            } else {
                rightMax = nums[r];
            }
            r--;
        }
    }

    return totalWater;
}

int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapingRainWater(nums) << endl;
    cout << trap(nums) << endl;
    return 0;
}