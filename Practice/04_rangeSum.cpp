#include <bits/stdc++.h>
using namespace std;


/*
    1508. Range Sum of Sorted Subarray Sums
You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous 
subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
Since the answer can be a huge number return it modulo 109 + 7. 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13.
*/

int mod = 1e9 + 7;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> ans;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum = (currentSum + nums[j]) % mod;
            ans.push_back(currentSum);
        }
    }

    sort(ans.begin(), ans.end());

    long long sum = 0;
    for (int i = left - 1; i < right; i++) {
        sum = (sum + ans[i]) % mod;
    }

    return (int)sum;
}

int main(){
    int n = 4; 
    vector<int> arr = {1, 2, 3, 4};
    int left = 1; 
    int right = 5;

    cout << rangeSum(arr, n, left, right);
    return 0;
}