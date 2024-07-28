#include<bits/stdc++.h>
using namespace std;


int f(int n,vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1,dp) + f(n-2,dp);
}

// converting recursion to tabulation
int fTabu(int n,vector<int> &dp){
    dp[1] = 1;
    dp[0] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// here we have used extra space dp array we have to replace it
int fTabuOptimized(int n){
    int pre1 = 1;
    int pre2 = 0;
    for(int i = 2; i <= n; i++){
        int res = pre1 + pre2;
        pre2 = pre1;
        pre1 = res;
    }
    return pre1;
}
int main()
{
    int n = 10;
    // cin >> n;
    vector<int> dp(n + 1, -1);
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);
    cout<< f(n,dp) << " ";
    cout<< fTabu(n,dp) << " ";
    cout<< fTabuOptimized(n);
    return 0;
}
