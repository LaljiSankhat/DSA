#include <bits/stdc++.h>
using namespace std;


/*
   LeetCode : 518. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount r
epresenting a total amount of money.Return the number of combinations that make up that amount. If that amount
 of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer. 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10]
Output: 1 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000
*/

/* this based on same concept of Q.20,21 where we can select multiple times an element */
int countCombinations(int i, int target, vector<int> &coins){
    if(i == 0){
        if(target % coins[i] == 0) return 1;
        else return 0;
    }

    int notTake = countCombinations(i - 1, target, coins);
    int take = 0;
    if(target >= coins[i]) take = countCombinations(i, target - coins[i], coins);
    
    return notTake + take;
}

// Memoization
int countCombinationsDp(int i, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(i == 0){
        if(target % coins[0] == 0) return 1;
        else return 0;
    }
    if(dp[i][target] != -1) return dp[i][target];

    int notTake = countCombinationsDp(i - 1, target, coins, dp);
    int take = 0;
    if(target >= coins[i]) take = countCombinationsDp(i, target - coins[i], coins, dp);
    
    return dp[i][target] = notTake + take;
}

// Tabulation
int countCombinationsTab(int n, int target, vector<int> &coins){
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for(int i = 0; i <= target; i++) dp[0][i] = (i % coins[0] == 0);

    //Loops
    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){
            int notTake = dp[i - 1][t];
            int take = 0;
            if (t >= coins[i])
                take = dp[i][t - coins[i]];
            dp[i][t] = notTake + take;
        }
    }

    return dp[n - 1][target];
}

// space optimization
int countCombinationsSpace(int n, int target, vector<int> &coins){
    vector<int> cur(target + 1, 0), prev(target + 1, 0);
    for(int i = 0; i <= target; i++) prev[i] = (i % coins[0] == 0);

    //Loops
    for(int i = 1; i < n; i++){
        for(int t = 0; t <= target; t++){
            int notTake = prev[t];
            int take = 0;
            if (t >= coins[i])
                take = cur[t - coins[i]];
            cur[t] = notTake + take;
        }
        prev = cur;
    }

    return prev[target];
}

int main(){
    vector<int> coins = {1,2,5};
    int target = 5;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << countCombinations(n - 1, target, coins) << endl;
    cout << countCombinationsDp(n - 1, target, coins, dp) << endl;
    cout << countCombinationsTab(n, target, coins) << endl;
    cout << countCombinationsSpace(n, target, coins) << endl;
    return 0;
}