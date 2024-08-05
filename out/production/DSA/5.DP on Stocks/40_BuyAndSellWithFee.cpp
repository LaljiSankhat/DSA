#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode : 714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day,
 and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like,
 but you need to pay the transaction fee for each transaction.

Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale. 

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 
Constraints:
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

/* This is as same as 36 but here we have to add transaction fee for every transaction like the group of buy and sell 
    considered as one transaction
*/
/* to Solve this Q we copy the code from 36 and add transaction fee in every transaction    */


int profit(int i, bool buy, vector<int> &prices, int fee){
    if(i == prices.size()) return 0;
    // if prices are over then you dont have to buy or sell you have just return 0

    // if buying
    if(buy){
        return max(-prices[i] + profit(i + 1, 0, prices, fee), // decided to buy
                    0 + profit(i + 1, 1, prices, fee)); // not to buy
    }
    // if selling
    return max(prices[i] - fee + profit(i + 1, 1, prices, fee), // decided to sell
                0 + profit(i + 1, 0, prices, fee)); // not to sell
}

// Memoization
int profitDp(int i, bool buy,vector<int> &prices, vector<vector<int>> &dp, int fee){
    if(i == prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];

    if(buy){
        return dp[i][buy] = max(-prices[i] + profitDp(i + 1, 0, prices, dp, fee), 0 + profitDp(i + 1, 1, prices, dp, fee));
    } 
    return dp[i][buy] = max(prices[i] - fee + profitDp(i + 1, 1, prices, dp, fee), 0 + profitDp(i + 1, 0, prices, dp, fee));
}

// Tabulation
int profitTab(int n, vector<int> &prices, int fee){
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], 0 + dp[i + 1][0]);
        }
    }

    return dp[0][1];
}

// space optimization
int profitSpace(int n, vector<int> &prices, int fee){
    vector<int> next(2, 0), cur(2, 0);
    next[0] = next[1] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                cur[buy] = max(-prices[i] + next[0], next[1]);
            }
            else cur[buy] = max(prices[i] - fee + next[1], 0 + next[0]);
        }
        next = cur;
    }

    return next[1];
}

// we can give - fee buy also it will give correct answer

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int n = prices.size();
    int fee = 2;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << profit(0, 1, prices, fee) << endl;
    cout << profitDp(0, 1, prices,dp, fee) << endl;
    cout << profitTab(n, prices, fee) << endl;
    cout << profitSpace(n, prices, fee) << endl;
    return 0;
}