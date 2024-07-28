#include <bits/stdc++.h>
using namespace std;

/*
  Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’.
Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/

// recursion
bool subsetSum(int i, int target, vector<int> &arr){
    if (target < 0)
        return false;
    if (i < 0)
        return false;
    if (arr[i] == target)
        return true;

    // explore all possibilities
    bool take = subsetSum(i - 1, target - arr[i], arr);
    bool notTake = subsetSum(i - 1, target, arr);

    return take || notTake;
}

// memoiazation
bool subsetSumDp(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // if(target < 0) return false;
    // if(i < 0) return false;
    if (target == 0)
        return true;
    if (i == 0)
        return (arr[i] == target);
    if (dp[i][target] != -1)
        return dp[i][target];

    // explore all possibilities
    bool notTake = subsetSumDp(i - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[i])
        take = subsetSumDp(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = take || notTake;
}

// Tabulation
bool subsetSumTab(int a, int target, vector<int> &arr, vector<vector<int>> &dp){
    for (int i = 0; i < dp.size(); i++)
        dp[i][0] = true;
    if(arr[0] <= target) dp[0][arr[0]] = true;
    for (int i = 1; i < arr.size(); i++){
        for (int k = 1; k <= target; k++){
            bool notTake = dp[i - 1][k];
            bool take = false;
            if (k >= arr[i])
                take = dp[i - 1][k - arr[i]];
            dp[i][k] = take || notTake;
        }
    }
    return dp[arr.size() - 1][target];
}

// space optimization
bool subsetSumSpace(int target, vector<int> &arr){
    vector<bool> prev(target + 1, 0), cur(target + 1, 0);
    prev[0] = cur[0] = true;
    if(arr[0] <= target) prev[arr[0]] = true;
    for (int i = 1; i < arr.size(); i++){
        for (int k = 1; k <= target; k++){
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

int main(){
    vector<int> arr = {6, 2, 1, 1};
    int target = 4;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << subsetSum(arr.size() - 1, target, arr) << endl;
    cout << subsetSumDp(arr.size() - 1, target, arr, dp) << endl;
    cout << subsetSumTab(arr.size() - 1, target, arr, dp) << endl;
    cout << subsetSumSpace(target, arr) << endl;

    return 0;
}