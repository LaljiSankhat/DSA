#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode : 123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple 
transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

/*  Solution is as same as previous but here we have to add one more parameter called cap which will 
    track the how many transaction is done of remaining to done 
*/

/* So we have to copy the code and we will add one parameter*/

int profit(int i, bool buy, vector<int> &prices, int cap){
    if(cap == 0) return 0;
    if(i == prices.size()) return 0;
    // if prices are over then you dont have to buy or sell you have just return 0

    // if buying
    if(buy){
        return max(-prices[i] + profit(i + 1, 0, prices, cap), // decided to buy
                    0 + profit(i + 1, 1, prices, cap)); // not to buy
    }
    // if selling
    return max(prices[i] + profit(i + 1, 1, prices, cap - 1), // decided to sell
                0 + profit(i + 1, 0, prices, cap)); // not to sell
}

//memoization
int profitDp(int i, bool buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp){
    if(cap == 0) return 0;
    if(i == prices.size()) return 0;
    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
    // if prices are over then you dont have to buy or sell you have just return 0

    // if buying
    if(buy){
        return dp[i][buy][cap] = max(-prices[i] + profitDp(i + 1, 0, prices, cap, dp), // decided to buy
                    0 + profitDp(i + 1, 1, prices, cap, dp)); // not to buy
    }
    // if selling
    return dp[i][buy][cap] = max(prices[i] + profitDp(i + 1, 1, prices, cap - 1, dp), // decided to sell
                0 + profitDp(i + 1, 0, prices, cap, dp)); // not to sell
}

// Tabulation
int profitTab(int n, vector<int> &prices){
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // for(int i = 0; i < n; i++){
    //     for(int buy = 0; buy <= 1; buy++){
    //         dp[i][buy][0] = 0;
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     for(int cap = 0; cap <= 2; cap++){
    //         dp[i][0][cap] = 0;
    //     }
    // }

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if (buy == 1){
                    dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
                }
                else
                    dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
            }
        }
    }

    return dp[0][1][2];
}

// Space Optimization
int profitSpace(int n, vector<int> &prices){
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if (buy == 1){
                    cur[buy][cap] = max(-prices[i] + after[0][cap], after[1][cap]);
                }
                else
                    cur[buy][cap] = max(prices[i] + after[1][cap - 1], 0 + after[0][cap]);
            }
        }
        after = cur;
    }

    return after[1][2];
}

/* we can solve this question using dp[n][4] */

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    cout << profit(0, 1, prices, 2) << endl;
    cout << profitDp(0, 1, prices, 2, dp) << endl;
    cout << profitTab(n,prices) << endl;
    cout << profitSpace(n,prices) << endl;
    return 0;
}