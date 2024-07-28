#include <bits/stdc++.h>
using namespace std;


/*
  LeetCode : 494. Target Sum

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before
" each integer " in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

/* here i have two case either i will put + or 0 the i will sum it to a sum variable return sum of both cases */

int targetSum(int i, int sum, int target, vector<int> &nums){
    if(i == 0){
        int ans = 0;
        if(sum + nums[i] == target) ans += 1;
        if(sum - nums[i] == target) ans += 1;
        return ans;
    }

    //take -
    int takeMinus = targetSum(i - 1, sum - nums[i], target, nums);
    int takePlus = targetSum(i - 1, sum + nums[i], target, nums);

    return (takeMinus + takePlus);
}

// memoization  (some error in this)
// int targetSumDp(int i, int sum, int target, vector<int> &nums, vector<vector<int>> &dp){
//     if(i == 0){
//         int ans = 0;
//         if(sum + nums[i] == target) ans += 1;
//         if(sum - nums[i] == target) ans += 1;
//         return ans;
//     }
//     if(dp[i][sum] != -1) return dp[i][sum];

//     //take -
//     int takeMinus = targetSumDp(i - 1, sum - nums[i], target, nums, dp);
//     int takePlus = targetSumDp(i - 1, sum + nums[i], target, nums, dp);

//     return dp[i][sum] = (takeMinus + takePlus);
// }

// // Tabulation
// int targetSumTab(int n, int target, vector<int> &nums){
//     vector<vector<int>> dp(n, vector<int>(target + 1, 0));

//     //base case
//     dp[0][target - nums[0]] = 1;

//     for(int i = 0; i < n; i++){
//         for(int sum = 0; sum <= target; sum++){
//             int takeMinus = dp[i - 1][sum - nums[i]];
//             int takePlus = dp[i - 1][sum + nums[i]];;
//             dp[i][sum] = (takeMinus + takePlus);
//         }
//     }
//     return dp[n - 1][target];
// }


/* method 2 : 
  
   we can solve like we can divid array into two subsets then difference of sum of both partion is equal to the target
   we have done it before in S1 - S2 = D problem here we have to replace this D with our target.
   so this question is related to Q.18
 */

int countSubSetsDp(int ind, vector<int>& arr, int sum, vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];

    int pick = 0;
    if(sum >= arr[ind]) pick = countSubSetsDp(ind - 1, arr, sum - arr[ind], dp);
    int notPick = countSubSetsDp(ind - 1, arr, sum, dp);

    return dp[ind][sum] = pick + notPick;
}
int countSubSetsSpace(vector<int> &arr, int sum){
    int n = arr.size();
    vector<int> prev(sum + 1, 0), cur(sum + 1);
    if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    // changing states
    for(int i = 1; i < n; i++){
        for(int s = 0; s <= sum; s++){
            int pick = 0;
            if(s >= arr[i]) pick = prev[s - arr[i]];
            int notPick = prev[s];
            cur[s] = pick + notPick;
        }
        prev = cur;
    }

    //return part
    return prev[sum];
}

int countSubSetsWithDiff(vector<int> &arr, int D){
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    if(totalSum - D < 0 || ((totalSum - D) % 2)) return 0;
    int sum = (totalSum - D) / 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    return countSubSetsSpace(arr, sum);
}


int main(){
    vector<int> nums = {1,1,1,1,1};
    int n = nums.size();
    int target = 3;
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += nums[i];
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
    cout << countSubSetsWithDiff(nums, target) << endl;
    cout << targetSum(n - 1, 0, target, nums) << endl;
    // cout << targetSumDp(n - 1, 0, target, nums, dp) << endl;
    // cout << targetSumTab(n - 1, target, nums) << endl;
    return 0;
}