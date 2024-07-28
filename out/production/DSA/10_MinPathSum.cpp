#include <bits/stdc++.h>
using namespace std;


/*
 Leet code : 64. Minimum Path Sum
Medium
Topics
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
 which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

*/

// memoization
int minSum(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    int left = grid[i][j] + minSum(i - 1, j, dp, grid);
    int up = grid[i][j] + minSum(i, j - 1, dp, grid);
    return dp[i][j] = min(left,up);
}

// Tabulation
int minSumTab(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
    dp[0][0] = grid[0][0];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else{
                int left = grid[i][j];
                int up = grid[i][j];
                if(i > 0) up += dp[i - 1][j];
                else up += 1e9;
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization
int minSumSpaceOptimized(int m, int n, vector<vector<int>> &grid){
    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++){
        vector<int> cur(n, 0);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) cur[i] = grid[0][0];
            else{
                int up = grid[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += cur[j - 1];
                else left += 1e9;

                cur[j] = min(left,up);
            }
        }
        prev = cur;
    }
    return prev[n - 1];
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << minSum(m - 1, n - 1, dp, grid) << endl;
    cout << minSumTab(m, n, dp, grid) << endl;
    cout << minSumSpaceOptimized(m,n,grid) << endl;
    return 0;
}