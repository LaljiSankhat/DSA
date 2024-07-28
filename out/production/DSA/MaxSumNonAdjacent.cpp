#include <bits/stdc++.h>
using namespace std;

int maxSum(int n, vector<int> arr, vector<int> &dp)
{
    if (n == -1)
        return 0;

    if (n == 0)
        return arr[0];
    if (dp[n] != -1)
        return dp[n];
    int pick = arr[n] + maxSum(n - 2, arr, dp);
    int notPick = maxSum(n - 1, arr, dp);
    return dp[n] = max(pick, notPick);
}

// Tabulation

int tabulation(int n, vector<int> &arr, vector<int> &dp){
    dp[0] = arr[0];
    int neg = 0;
    int m = INT_MIN;
    for(int i = 1; i < n; i++){
        int take = arr[i];
        if(i - 2 > 0) take += dp[i - 2];
        int nonTake = 0 + dp[i - 1];
        nonTake = take;
        take = m;
    }
    return m;
}

// space optimised

int spaceOptimised(int n, vector<int> &arr){
    int prev2 = 0;
    int prev1 = arr[0];
    for(int i = 1; i < arr.size(); i++){
        int take = arr[i];
        if(i > 1) take += prev2;
        int notTake = prev1;
        int cur = max(take,notTake);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}


int main()
{
    vector<int> arr = {2, 7, 9, 3, 1};
    vector<int> dp(arr.size() + 1, -1);
    cout << maxSum(arr.size() - 1, arr, dp) << endl;
    cout << spaceOptimised(arr.size() - 1, arr) << endl;
    cout << tabulation(arr.size() - 1, arr,dp) << endl;
    // int m = INT_MIN;
    // for(int i = 0; i < arr.size(); i++){
    //     m = max(m,maxSum(i,arr,dp));
    // }
    // cout<<m<<endl;
    return 0;
}