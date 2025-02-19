#include <bits/stdc++.h>
using namespace std;

// leetcode : 2342 Max Sum of a Pair With Equal Sum of Digits

/*
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.



Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

int maxSum(vector<int> &nums){
    int n = nums.size();
    vector<int> digits;
    for (int i = 0; i < n; i++){
        // string s = to_string(nums[i]);
        // int sum = 0;
        // for (int j = 0; j < s.size(); j++){
        //     sum += s[j] - '0';
        // }
        // digits.push_back(sum);

        int num = nums[i];
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        digits.push_back(digitSum);
    }
    int maxSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(digits[i] == digits[j]){
                maxSum = max(nums[i] + nums[j], maxSum);
            }
        }
    }
    return maxSum;
}


int maxSumOptimised(vector<int> &nums){
    int n = nums.size();
    unordered_map<int, int> mp;
    int maxSum = -1;
    for(int num : nums){
        int digitSum = 0;
        int temp = num;
        while(temp > 0){
            digitSum += temp % 10;
            temp /= 10;
        }
        if(mp.find(digitSum) != mp.end()){
            maxSum = max(maxSum, mp[digitSum] + num);
            mp[digitSum] = max(mp[digitSum], num);
        } else {
            mp[digitSum] = num;
        }
        
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {18, 43, 36, 13, 7};
    int a = maxSum(nums);
    int b = maxSumOptimised(nums);
    cout << a << b << endl;
    return 0;
}