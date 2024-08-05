#include <bits/stdc++.h>
using namespace std;

/*

   LeetCode 213. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if 
two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money
you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

*/

int rob(vector<int> &arr){
    int prev2 = 0;
    int prev1 = arr[0];
    for (int i = 1; i < arr.size(); i++){
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int notTake = prev1;
        int cur = max(take, notTake);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int rob2(vector<int> &arr){
    vector<int> temp1, temp2;
    for (int i = 0; i < arr.size(); i++){
        if (i != 0)
            temp1.push_back(arr[i]);
        if (i != arr.size() - 1)
            temp2.push_back(arr[i]);
    }
    return max(rob(temp1), rob(temp2));
}

int main(){
    vector<int> arr = {5, 3, 7, 8, 2, 90, 23, 56};
    cout << rob2(arr) << endl;
    return 0;
}