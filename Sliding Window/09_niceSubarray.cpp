#include <bits/stdc++.h>
using namespace std;


/*
    1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays. 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

// to solve this we just need to count the number of odd and even elem in array 
// so we dont need of the array values 
// so we convert the array into binary array where if odd then 1 and even then 0
// then we can apply the prev logic as same
// so when there is 1 means it is odd number and we add it to sum which indirectly means the no of odd elems 
// so we need sum == k in binary subarray

int findSubarrayWithSumLessThanGoal(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int l = 0, r = 0, sum = 0, cnt = 0;

    while(r < n){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int noOfNiceSubarray(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> binaryNums(n, 0);

    for(int i = 0; i < n; i++){
        if(nums[i] % 2 == 1) binaryNums[i] = 1;
    }

    int sumLessGoal = findSubarrayWithSumLessThanGoal(binaryNums, k);
    int sumLessGoalMinusOne = findSubarrayWithSumLessThanGoal(binaryNums, k - 1);

    return sumLessGoal - sumLessGoalMinusOne;
}


int main(){
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    cout << noOfNiceSubarray(nums, k);
    return 0;
}