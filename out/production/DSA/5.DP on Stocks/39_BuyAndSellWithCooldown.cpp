#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode : 309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like
 (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0 

Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

/* this question is extention of question 36 but here we cannot buy the stock just after selling so this 
    Not buying right after selling is called cooldown.
*/

/* to solve this question we can say that when we selling index become i + 2 and that's it */

int profit(int i, bool buy, vector<int> &prices){
    if(i >= prices.size()) return 0;
    // if prices are over then you dont have to buy or sell you have just return 0

    // if buying
    if(buy){
        return max(-prices[i] + profit(i + 1, 0, prices), // decided to buy
                    0 + profit(i + 1, 1, prices)); // not to buy
    }
    // if selling
    return max(prices[i] + profit(i + 2, 1, prices), // decided to sell
                0 + profit(i + 1, 0, prices)); // not to sell
}

int profitTab(int n, vector<int> &prices){
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            if (buy){
                dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else dp[i][buy] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
        }
    }

    return dp[0][1];
}

// we can not space optimise it because we i + 2 (we can do this )
// but we can remove the internal loop
int profitTab2(int n, vector<int> &prices){
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int i = n - 1; i >= 0; i--){

        dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

        dp[i][0] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
    }

    return dp[0][1];
}

// Space optimization 
int profitSpace(int n, vector<int> &prices){
    vector<int> front2(2, 0);
    vector<int> front1(2, 0);
    vector<int> cur(2, 0);

    for(int i = n - 1; i >= 0; i--){

        cur[1] = max(-prices[i] + front1[0], front1[1]);

        cur[0] = max(prices[i] + front2[1], 0 + front1[0]);

        front2 = front1;
        front1 = cur;
    }

    return front1[1];
}


int main(){
    vector<int> prices = {1,2,3,0,2};
    int n = prices.size();
    cout << profit(0, 1, prices) << endl;
    cout << profitTab(n, prices) << endl;
    cout << profitTab2(n, prices) << endl;
    cout << profitSpace(n, prices) << endl;
    return 0;
}