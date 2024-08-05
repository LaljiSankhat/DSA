#include <bits/stdc++.h>
using namespace std;


/*
    LeetCode : 188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most 
k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

/* This problem is as same as previos problem but here we can do atmost k transactions */

//using privious question logic
int profitSpace(int n, vector<int> &prices, int k){
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= k; cap++){
                if (buy == 1){
                    cur[buy][cap] = max(-prices[i] + after[0][cap], after[1][cap]);
                }
                else
                    cur[buy][cap] = max(prices[i] + after[1][cap - 1], 0 + after[0][cap]);
            }
        }
        after = cur;
    }

    return after[1][k];
}

// using the concept of only f(index, transaction)  => dp[n][k]
int profit(int i, int t, vector<int> &prices, int n, int k){
    if(i == n || t == k) return 0; 
    // if index at n OR all transactions are done

    // have to buy
    if(t % 2 == 0){
        return max(-prices[i] + profit(i + 1, t + 1, prices, n, k), 0 + profit(i + 1, t, prices, n, k));
    }
    
    // have to sell
    return max(prices[i] + profit(i + 1, t + 1, prices, n, k), 0 + profit(i + 1, t, prices, n, k));
}

// memoization
int profitDp(int i, int t, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    if(i == n || t == k) return 0; 
    if(dp[i][t] != -1) return dp[i][t];
    // if index at n OR all transactions are done

    // have to buy
    if(t % 2 == 0){
        return dp[i][t] = max(-prices[i] + profitDp(i + 1, t + 1, prices, n, k, dp), 0 + profitDp(i + 1, t, prices, n, k, dp));
    }
    
    // have to sell
    return dp[i][t] = max(prices[i] + profitDp(i + 1, t + 1, prices, n, k, dp), 0 + profitDp(i + 1, t, prices, n, k, dp));
}

// tabulation
int profitTab(int i, int t, vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int t = k - 1; t >= 0; t--){
            if (t % 2 == 0){
                dp[i][t] = max(-prices[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
            }

            // have to sell
            else dp[i][t] = max(prices[i] + dp[i + 1][t + 1], 0 + dp[i + 1][t]);
        }
    }
    return dp[0][0];
}

// Space optimizaition
int profitSpace(int i, int t, vector<int> &prices, int n, int k){
    vector<int> ahead(k * 2 + 1, 0);
    vector<int> cur(k * 2 + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        for(int t = k - 1; t >= 0; t--){
            if (t % 2 == 0){
                cur[t] = max(-prices[i] + ahead[t + 1], 0 + ahead[t]);
            }

            // have to sell
            else cur[t] = max(prices[i] + ahead[t + 1], 0 + ahead[t]);
        }
        ahead = cur;
    }
    return ahead[0];
}

int main(){
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(k * 2 + 1, -1));
    cout << profitSpace(n, prices, k) << endl;
    cout << profit(0, 0, prices, n, k * 2) << endl;
    cout << profitDp(0, 0, prices, n, k * 2, dp) << endl;
    cout << profitTab(0, 0, prices, n, k * 2) << endl;
    cout << profitSpace(0, 0, prices, n, k * 2) << endl;
    return 0;
}