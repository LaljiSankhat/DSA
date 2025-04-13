#include <bits/stdc++.h>
using namespace std;


// leetcode 233. Number of Digit One

int solve(string &s, int pos, bool tight, int prev, vector<vector<vector<int>>> &dp){
    if(pos == s.length()) return prev;
    if(dp[pos][tight][prev] != -1) return dp[pos][tight][prev];

    int ub = tight ? s[pos] - '0' : 9;
    int ans = 0;

    for(int i = 0; i <= ub; i++){
        if(i == 1){
            ans += solve(s, pos + 1, tight & (i == ub), prev + 1, dp);
        } else {
            ans += solve(s, pos + 1, tight & (i == ub), prev, dp);
        }
    }

    return dp[pos][tight][prev] = ans;
}

int countDigitOne(int n){
    string s = to_string(n);
    vector<vector<vector<int>>> dp(20, vector<vector<int>>(2, vector<int>(s.size(), -1)));
    return solve(s, 0, 1, 0, dp);
}

int main(){
    int n = 13;
    cout << countDigitOne(n) << endl; // Output: 6 (1, 10, 11, 12, 13)
    return 0;
}