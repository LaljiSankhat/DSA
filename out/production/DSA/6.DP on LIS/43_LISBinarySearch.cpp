#include <bits/stdc++.h>
using namespace std;


/*
    LeetCode : 2407. Longest Increasing Subsequence II

You are given an integer array nums and an integer k.
Find the longest subsequence of nums that meets the following requirements:
The subsequence is strictly increasing and
The difference between adjacent elements in the subsequence is at most k.
Return the length of the longest subsequence that meets the requirements.
A subsequence is an array that can be derived from another array by deleting some or 
no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.

Example 2:
Input: nums = [7,4,5,1,8,12,4,7], k = 5
Output: 4
Explanation:
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.

Example 3:
Input: nums = [1,5], k = 1
Output: 1
Explanation:
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.
 
Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 105
*/
/* This is as same quetion but remove the k condition */
/* This is follow up of previuos quetion where we have achieved O(n ^ 2) time complexity it will give TLE for 10 ^ 5
test case so we have to optimize it */

/* To solve this we have to use binary search */
/* we create a vector of temp we check for every elem fit in temp if we get smaller than last elem of temp
then we do binay search for right position of that elem and overwrite it. it will not give us the subsequence
but it will give us the length 
*/

/* Here we are not generating the LIS we just find the length */

int lis(int n, vector<int> &nums){
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }

    return temp.size();
}

int main(){
    vector<int> nums = {4,2,1,4,3,4,5,8,15};
    // int k = 3;
    int n = nums.size();
    cout << lis(n, nums) << endl;
    return 0;
}