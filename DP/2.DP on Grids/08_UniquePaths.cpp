#include <bits/stdc++.h>
using namespace std;

/*     LeetCode 62

There is a robot on an m x n grid. The robot is initially located at the top-left corner
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can
take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

int uniquePath(int i, int j){
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    return uniquePath(i - 1, j) + uniquePath(i, j - 1);
}

// memoization
int uniquePathDp(int i, int j, vector<vector<int>> &dp){
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = uniquePathDp(i - 1, j, dp) + uniquePathDp(i, j - 1, dp);
}

// tabulation
int uniquePathTab(int m, int n, vector<vector<int>> &dp){
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization
int uniquePathSpaceOptimized(int m, int n){
    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++){
        vector<int> cur(n, 0);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) cur[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j - 1];
                cur[j] = up + left;
            }
        }
        prev = cur;
    }
    return prev[n - 1];
}

int uniquePathSpaceOptimizedSingleArray(int m, int n){
    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++){
        // vector<int> cur(n, 0);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) prev[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = prev[j - 1];
                prev[j] = up + left;
            }
        }
        // prev = cur;
    }
    return prev[n - 1];
}

int main()
{
    int m = 2;
    int n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << uniquePath(m - 1, n - 1) << endl;
    cout << uniquePathDp(m - 1, n - 1, dp) << endl;
    cout << uniquePathTab(m,n,dp) << endl;
    cout << uniquePathSpaceOptimized(m,n) << endl;
    cout << uniquePathSpaceOptimizedSingleArray(m,n) << endl;
    return 0;
}