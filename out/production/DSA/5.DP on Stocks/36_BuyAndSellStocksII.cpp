#include <bits/stdc++.h>
using namespace std;


/*
    LeetCode : 122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve. 

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0. 

Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

/* To solve : 
    Either you don't buy any stock
        Then either you buy or not to buy and move forword
    Or you buyed a stock and now you have to sell it
        Then either you sell or not to sell
*/

/* We have to keep a buy variable to check wether we have to buy or sell
   if buy = 1 
        Then you have to Buy
    if buy = 0
        Then you have to sell
 */

int profit(int i, bool buy, vector<int> &prices){
    if(i == prices.size()) return 0;
    // if prices are over then you dont have to buy or sell you have just return 0

    // if buying
    if(buy){
        return max(-prices[i] + profit(i + 1, 0, prices), // decided to buy
                    0 + profit(i + 1, 1, prices)); // not to buy
    }
    // if selling
    return max(prices[i] + profit(i + 1, 1, prices), // decided to sell
                0 + profit(i + 1, 0, prices)); // not to sell
}

// Memoization
int profitDp(int i, bool buy,vector<int> &prices, vector<vector<int>> &dp){
    if(i == prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];

    if(buy){
        return dp[i][buy] = max(-prices[i] + profitDp(i + 1, 0, prices, dp), 0 + profitDp(i + 1, 1, prices, dp));
    } 
    return dp[i][buy] = max(prices[i] + profitDp(i + 1, 1, prices, dp), 0 + profitDp(i + 1, 0, prices, dp));
}

// Tabulation
int profitTab(int n, vector<int> &prices){
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else dp[i][buy] = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
        }
    }

    return dp[0][1];
}

// space optimization
int profitSpace(int n, vector<int> &prices){
    vector<int> next(2, 0), cur(2, 0);
    next[0] = next[1] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                cur[buy] = max(-prices[i] + next[0], next[1]);
            }
            else cur[buy] = max(prices[i] + next[1], 0 + next[0]);
        }
        next = cur;
    }

    return next[1];
}

// using only variables
int profitSpace2(int n, vector<int> &prices){
    int nextSell = 0;
    int nextBuy = 0;

    for(int i = n - 1; i >= 0; i--){
        int curBuy = 0;
        int curSell = 0;
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                curBuy = max(-prices[i] + nextSell, nextBuy);
            }
            else curSell = max(prices[i] + nextBuy, 0 + nextSell);
        }
        nextSell = curSell;
        nextBuy = curBuy;
    }

    return nextBuy;
}

int profitSpace3(int n, vector<int> &prices){
    int aheadNotBuy, aheadBuy, curNotBuy, curBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int i = n - 1; i >= 0; i--){
        int curBuy = 0;
        int curSell = 0;
        curBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
        curNotBuy = max(prices[i] + aheadBuy, 0 + aheadNotBuy);
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }

    return aheadBuy;
}

int p(vector<int> &prices){
    int n = prices.size();
    int profit = 0;
    for(int i = 0; i < n - 1; i++){
        if(prices[i + 1] > prices[i]) profit += prices[i + 1] - prices[i];
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << profit(0, 1, prices) << endl;
    cout << profitDp(0, 1, prices,dp) << endl;
    cout << profitTab(n,prices) << endl;
    cout << profitSpace(n,prices) << endl;
    cout << profitSpace2(n,prices) << endl;
    cout << profitSpace3(n,prices) << endl;
    vector<int> pt = {1,2,3,4,5};
    cout << p(pt) << endl;
    cout << profit(0, 1, pt) << endl;
    return 0;
}