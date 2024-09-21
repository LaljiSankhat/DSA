#include <bits/stdc++.h>
using namespace std;

// leetcode : 53. Maximum Subarray
/*
    Kadane's Algorithm is a popular algorithm used to solve the Maximum Subarray Sum problem. 
    The goal is to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum.
*/

// Kadane's Algorithm 
// so here we have to find the max sum subarray 
// so we will maintain a current sum and global sum variable 
// at every index we add elem to current sum if current sum is greater than elem then no need to start new subarray
// if elem is greater then current sum then we start new subarray by current_sum = elem
// at every step we check for global maximum also

int kadanesAlgorithm(vector<int> nums){
    int n = nums.size();
    int globalSum = nums[0];
    int currentSum = nums[0];

    for(int i = 1; i < n; i++){
        currentSum = max(currentSum + nums[i], nums[i]);
        globalSum = max(globalSum, currentSum);
    }

    return globalSum;
}


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << kadanesAlgorithm(nums);
    return 0;
}