#include <bits/stdc++.h>
using namespace std;


/*
  LeetCode : 931. Minimum Falling Path Sum

  Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. Specifically, the next element from position (row, col) 
will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
*/


int minSum(int i, int j, vector<vector<int>> &mat){
    if(j < 0 || j > mat.size() - 1) return 1e9;
    if(i == 0) return mat[0][j];

    // all posible cases
    int up = mat[i][j] + minSum(i - 1, j,mat);
    int dl = mat[i][j] + minSum(i - 1, j - 1, mat);
    int dr = mat[i][j] + minSum(i - 1, j + 1, mat);

    return min(up, min(dl,dr));
}

// memoization
int minSumDp(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(j < 0 || j > mat.size() - 1) return 1e9;
    if(i == 0) return mat[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    // all posible cases
    int up = mat[i][j] + minSumDp(i - 1, j,mat,dp);
    int dl = mat[i][j] + minSumDp(i - 1, j - 1, mat,dp);
    int dr = mat[i][j] + minSumDp(i - 1, j + 1, mat,dp);

    return dp[i][j] = min(up, min(dl,dr));
} 

// Tabulation
int minSumTab(vector<vector<int>> &mat, vector<vector<int>> &dp){
    int n = mat.size();
    for(int i = 0; i < n; i++){
        dp[0][i] = mat[0][i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int up = mat[i][j] + dp[i - 1][j];
            int ld = mat[i][j];
            int rd = mat[i][j];
            if(j > 0) ld += dp[i - 1][j - 1];
            else ld += 1e9;
            if(j < mat.size() - 1) rd += dp[i - 1][j + 1];
            else rd += 1e9;
            dp[i][j] = min(up,min(ld,rd));
        }
    }

    int ans = dp[n - 1][0];
    for(int i = 1; i < n; i++){
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}

// Space optimization

int minSumSpaceOptimization(vector<vector<int>> &mat){
    int n = mat.size();
    vector<int> prev(n,0);
    for(int i = 0; i < n; i++){
        prev[i] = mat[0][i];
    }

    for(int i = 1; i < n; i++){
        vector<int> cur(n,0);
        for(int j = 0; j < n; j++){
            int up = mat[i][j] + prev[j];
            int ld = mat[i][j];
            int rd = mat[i][j];
            if(j > 0) ld += prev[j - 1];
            else ld += 1e9;
            if(j < mat.size() - 1) rd += prev[j + 1];
            else rd += 1e9;
            cur[j] = min(up,min(ld,rd));
        }
        prev = cur;
    }

    int ans = prev[0];
    for(int i = 1; i < n; i++){
        ans = min(ans, prev[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    int n = matrix.size();
    vector<vector<int>> dp(n,  vector<int>(n, -1));
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        ans = min(ans, minSum(n - 1, i, matrix));
    }
    cout << ans << endl;
    int a = 1e9;
    for(int i = 0; i < n; i++){
        a = min(a, minSumDp(n - 1, i, matrix,dp));
    }
    cout << a << endl;
    cout << minSumTab(matrix, dp) << endl;
    cout << minSumSpaceOptimization(matrix) << endl;
    return 0;
}