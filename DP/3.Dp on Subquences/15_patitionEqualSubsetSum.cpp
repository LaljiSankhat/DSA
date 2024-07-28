#include <bits/stdc++.h>
using namespace std;


/*
  LeetCode: 416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
this is same as Q.14 if divide array in two parts and if we get target = sum of array/2 then we can say that remaining part of
array will also have sum = sum of array/2

if get the one part then return true otherwise return false
*/

// space optimization of Q.14
bool subsetSumSpace(int target, vector<int> &arr){
    vector<bool> prev(target + 1, 0), cur(target + 1, 0);
    prev[0] = cur[0] = true;
    if(arr[0] <= target) prev[arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool notTake = prev[k];
            bool take = false;
            if (k >= arr[i])
                take = prev[k - arr[i]];
            cur[k] = take || notTake;
        }
        prev = cur;
    }
    return prev[target];
}

bool canPartition(vector<int> &arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) sum += arr[i];
    if(sum % 2 != 0) return false;
    return subsetSumSpace(sum / 2, arr);
}


int main(){
    vector<int> arr = {5,11,5};
    cout << canPartition(arr) << endl;
    return 0;
}