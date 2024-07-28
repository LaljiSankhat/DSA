#include <bits/stdc++.h>
using namespace std;


/*
  Leet Code 120 : Triangle

  Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
*/

int minPathSum(int i, int j, vector<vector<int>> &triangle){
    if(i == triangle.size() - 1) return triangle[i][j];

    int down = triangle[i][j] + minPathSum(i + 1, j, triangle);
    int dia = triangle[i][j] + minPathSum(i + 1, j + 1, triangle);

    return min(down,dia);
}

// memoization

int minPathSumDp(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    if(i == triangle.size() - 1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + minPathSumDp(i + 1, j, triangle,dp);
    int dia = triangle[i][j] + minPathSumDp(i + 1, j + 1, triangle,dp);

    return dp[i][j] = min(down,dia);
}

// Tabulation

int minPathSumTab(vector<vector<int>> &triangle, vector<vector<int>> &dp){
    int m = triangle.size();
    dp[0][0] = triangle[0][0];

    for(int i = 1; i < m; i++){
        for(int j = 0; j < i + 1; j++){
            if(j == 0){
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            }else if(j == i){
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            }else{
                int down = triangle[i][j] + dp[i - 1][j];
                int dia = triangle[i][j] + dp[i - 1][j - 1];
                dp[i][j] = min(down,dia);
            }
        }
    }

    int minSum = 1e9;
    for(int i = 0; i < m; i++){
        minSum = min(minSum, dp[m - 1][i]);
    }
    return minSum;
}

// Tabulation (n-1) to 0

int minPathSumTab2(vector<vector<int>> &triangle, vector<vector<int>> &dp){
    int m = triangle.size();

    for(int i = 0; i < m; i++){
        dp[m - 1][i] = triangle[m - 1][i];
    }

    for(int i = m - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            if(m == 0 && j == 0) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            else{
                int down = triangle[i][j] + dp[i + 1][j];
                int dia = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, dia);
            }
        }
    }

    return dp[0][0];
}

// Space Optimization

int minPathSumSpaceOptimised(vector<vector<int>> &triangle){
    int n = triangle.size();

    vector<int> prev(n, 0);
    for(int i = 0; i < n; i++){
        prev[i] = triangle[n - 1][i];
    }

    for(int i = n - 2; i >= 0; i--){
        vector<int> cur(n,1e9);
        for(int j = i; j >= 0; j--){
            if(i == 0){
                cur[j] = min(prev[j], prev[j + 1]) + triangle[i][j];
            }else{
                int down = triangle[i][j] + prev[j];
                int dia = triangle[i][j] + prev[j + 1];
                cur[j] = min(down, dia); 
            }
        }
        prev = cur;
    }
    return prev[0];
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    cout << minPathSum(0,0,triangle) << endl;
    cout << minPathSumDp(0,0,triangle,dp) << endl;
    cout << minPathSumTab(triangle,dp) << endl;
    cout << minPathSumTab2(triangle,dp) << endl;
    cout << minPathSumSpaceOptimised(triangle) << endl;
    return 0;
}