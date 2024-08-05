#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n){
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int left = climbStairs(n - 1);
    int right = climbStairs(n - 2);
    return left + right;
}

// in this case time limit exceed so we have to memoize that

int climbStairsMemoize(int n,vector<int> &dp){
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int left = 0;
    int right = 0;
    if(dp[n - 1] != -1) left = dp[n-1];
    else {
        left = climbStairs(n - 1);
    }
    if(dp[n - 2] != -1) right = dp[n-2];
    else {
        right = climbStairs(n - 2);
    }
    
    return dp[n] = left + right;
}

// Tabulation
int stairTab(int n,vector<int> &dp){
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// space optimised
int spaceOpti(int n){
    int pre1 = 1;
    int pre2 = 1;
    for(int i = 2; i <= n; i++){
        int res = pre1 + pre2;
        pre2 = pre1;   
        pre1 = res;
    }
    return pre1;
}

int main(){
    int n = 44;
    vector<int> dp(n + 1, -1);
    cout<< climbStairsMemoize(n,dp)<< endl;
    cout<< stairTab(n,dp) << endl;
    cout<< spaceOpti(n);
    return 0;
}