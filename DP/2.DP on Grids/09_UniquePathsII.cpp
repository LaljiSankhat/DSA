#include <bits/stdc++.h>
using namespace std;


/*
63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. 
A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

*/


int uniquePathDp(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid){
    if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = uniquePathDp(i - 1, j, dp,grid) + uniquePathDp(i, j - 1, dp,grid);
}

// tabulation
int uniquePathTab(int m, int n, vector<vector<int>> &dp,vector<vector<int>> &grid){
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
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
int uniquePathSpaceOptimized(int m, int n, vector<vector<int>> &grid){
    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++){
        vector<int> cur(n, 0);
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) cur[j] = 0;
            else if(i == 0 && j == 0) cur[j] = 1;
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

int main(){
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << uniquePathDp(m - 1, n - 1, dp,grid) << endl;
    cout << uniquePathTab(m,n,dp,grid) << endl;
    cout << uniquePathSpaceOptimized(m,n,grid) << endl;
    return 0;
}