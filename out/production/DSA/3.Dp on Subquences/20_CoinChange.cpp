#include <bits/stdc++.h>
using namespace std;


/*
  LeetCode : 322. Coin Change
You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be
made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin. 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

*/

/*  
  there is a twist in this question that we can take element many times there is no limit in taking a element.
  so all possibilities we have another possibilities other than take and notTack
  so posibilities : 
    1. notTake => 0 + f(index - 1, target)
    2. take => if(coin[index] <= target) then 
                    take = coin[index] + f(index, target - coin[i])

  pattern : if question has infinite supply, multiple use then in take we always stands that index

*/

int minCoins(int ind, int target, vector<int> &coins){
    // base case
    if(ind == 0){
        if(target % coins[ind] == 0) return (target / coins[ind]);
        else return 1e9;  // not INT_MAX because it will add into 1 (line 60) and it will give error
    }

    // all possibilities
    int notTake = 0 + minCoins(ind - 1, target, coins);
    int take = INT_MAX;
    if(coins[ind] <= target) take = 1 + minCoins(ind, target - coins[ind], coins);

    return min(notTake, take);
}
// here we have to choose one many so TC will greater than 2^N we can say it like "Exponential"
// SC = O(Target) because we can call untill target become zero

// memoization
/* there two changing states target and index */
int minCoinsDp(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
    // base case
    if(ind == 0){
        if(target % coins[ind] == 0) return (target / coins[ind]);
        else return 1e9;  // not INT_MAX because it will add into 1 (line 60) and it will give error
    }
    if(dp[ind][target] != -1) return dp[ind][target];

    // all possibilities
    int notTake = 0 + minCoinsDp(ind - 1, target, coins, dp);
    int take = INT_MAX;
    if(coins[ind] <= target) take = 1 + minCoinsDp(ind, target - coins[ind], coins, dp);

    return  dp[ind][target] = min(notTake, take);
}
/* TC = O(N * Target) SC = O(N * Target) + O(Target) */

//Tabulation
int minCoinsTab(int n, int target, vector<int> &coins){
     vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // base cases
    for(int i = 0; i <= target; i++){
        if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        else dp[0][i] = 1e9;
    }

    // Loops
    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){
            int notTake = 0 + dp[i - 1][t];
            int take = INT_MAX;
            if (coins[i] <= t) take = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(notTake, take);
        }
    }

    return dp[n - 1][target];
}
/* TC = O(n * target) SC = O(Target) */

// space optimization
int minCoinsSpace(int n, int target, vector<int> &coins){
    vector<int> cur(target + 1, 0), prev(target + 1, 0);
    for(int i = 0; i <= target; i++){
        if(i % coins[0] == 0) prev[i] = i / coins[0];
        else prev[i] = 1e9;
    }

    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){
            int notTake = 0 + prev[t];
            int take = INT_MAX;
            if (coins[i] <= t) take = 1 + cur[t - coins[i]];
            cur[t] = min(notTake, take);
        }
        prev = cur;
    }

    return prev[target];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    cout << minCoins(n - 1, amount, coins) << endl;
    cout << minCoinsDp(n - 1, amount, coins, dp) << endl;
    cout << minCoinsTab(n, amount, coins) << endl;
    cout << minCoinsSpace(n, amount, coins) << endl;
    return 0;
}

