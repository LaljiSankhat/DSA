#include <bits/stdc++.h>
using namespace std;


// given an array of cards of points 
// we have to take k cards consecutively

// leetCode : 1423. Maximum Points You Can Obtain from Cards

// we can take cards from front and back only no from middle

int maxScore(vector<int> &nums, int k){
    int n = nums.size();
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;
    for(int i = 0; i < k; i++){
        leftSum += nums[i];
    }
    maxSum = leftSum;

    int rightIndex = n - 1;
    for(int i = k - 1; i >= 0; i--){
        leftSum -= nums[i];
        rightSum += nums[rightIndex];
        rightIndex--;
        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << maxScore(nums, k);
    return 0;
}