#include <bits/stdc++.h>
using namespace std;


// leetcode : 1749 Maximum Absolute Sum of Any Subarray



// always remeber for -ve things sliding window will fail
// int maxSubarrayAbsoluteSum(vector<int> &nums){
//     int n = nums.size();
//     int l = 0, r = 0;
//     int maxSum = 0, curSum = 0;
//     int preSum = 0;

//     while(r < n){
//         preSum = abs(curSum);
//         curSum += nums[r];
//         maxSum = max(maxSum, abs(curSum));
//         while(l <= r && abs(curSum) < preSum){
//             curSum -= nums[l];
//             l++;
//         }
//         r++;
//     }
//     return maxSum;
// }


// so Kdanes algo
int maxSumSubarray(vector<int> &nums){
    int n = nums.size();
    int maxSum = nums[0];
    int curSum = nums[0];

    for(int i = 1; i < n; i++){
        curSum = max(curSum + nums[i], nums[i]);
        maxSum = max(maxSum, curSum);
    }
    cout << maxSum << endl;
    return maxSum;
}
int minSumSubarray(vector<int> &nums){
    int n = nums.size();
    int minSum = nums[0];
    int curSum = nums[0];

    for(int i = 1; i < n; i++){
        curSum = min(curSum + nums[i], nums[i]);
        minSum = min(minSum, curSum);
    }
    cout << minSum << endl;
    return minSum;
}
int maxSubarrayAbsoluteSum(vector<int> &nums){
    return max(abs(maxSumSubarray(nums)), abs(minSumSubarray(nums)));
}


int main(){
    vector<int> nums = {-7,-1,0,-2,1,3,8,-2,-6,-1,-10,-6,-6,8,-4,-9,-4,1,4,-9};
    cout << maxSubarrayAbsoluteSum(nums) << endl;
    return 0;
}