#include <bits/stdc++.h>
using namespace std;


// leetcode 790. Domino and Tromino Tiling


int MOD = 1e9 + 7;

int helper(int n, vector<int> &dp){
    if(n <= 1) return 1;
    if(n == 2) return 2;
    if(dp[n] != -1) return dp[n];
    return dp[n] = ((helper(n - 1, dp) * 2) % MOD + helper(n - 3, dp)) % MOD;
}

int numTilings(int n) {
    vector<int> dp(n + 1, -1);
    return helper(n, dp);
}


int main(){
    int n = 10;
    cout << numTilings(n) << endl;
    return 0;
}