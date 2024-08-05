#include <bits/stdc++.h>
using namespace std;

// Tabulation approch of previos question

int matrixChainMultiplicationTab(int n, vector<int> &arr, vector<vector<int>> &dp){
    // Base Case
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    // Loops for changing parameters
    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n - 1];

    // Try all possible ways
    // int mini = 1e9;
    // for(int k = i; k < j; k++){
    //     int steps = (arr[i - 1] * arr[k] * arr[j]) 
    //                 + matrixChainMultiplicationDp(i, k, arr, dp) + matrixChainMultiplicationDp(k + 1, j, arr, dp);
    //     mini = min(mini, steps);    
    // }

    // return dp[i][j] = mini;
}

int main(){
    vector<int> arr = {10, 15, 20, 25};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << matrixChainMultiplicationTab(n, arr, dp) << endl;
    return 0;
}