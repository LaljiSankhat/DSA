#include <bits/stdc++.h>
using namespace std;


/* 
    260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements 
appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space. 

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]

Constraints:
2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

// to solve this we use two buckets
// first we xor the all numbers of array
// then we take right most bit of xored result which will tell the that bit is different in the both the numbers
// so in first buket we put number which has that bit set
// number for which that bit is not set will put into second bucket
// now we sure that two distinct number always stay in different buckets
// so we need to xor all the elements of the bukets
// hence we get ans in our buckets

pair<int, int> singleNumberIII(int n, vector<int> &arr){
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp = temp ^ arr[i];
    }

    int rightMostBitNum = 0;
    if(temp == INT_MIN){
        rightMostBitNum = 1;
    } else {
        rightMostBitNum = ((temp & (temp - 1)) ^ temp);
    }

    int bucket1 = 0;
    int bucket2 = 0;

    for(int i = 0; i < n; i++){
        if((rightMostBitNum & arr[i]) != 0){
            bucket1 = bucket1 ^ arr[i];
        } else {
            bucket2 = bucket2 ^ arr[i];
        }
    }

    return {bucket1, bucket2};
}


int main(){
    vector<int> arr = {1, 2, 5, 2, 1, 6};
    int n = arr.size();
    pair<int, int> ans = singleNumberIII(n, arr);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}