#include <bits/stdc++.h>
using namespace std;


// 2338. Count the Number of Ideal Arrays

int helper(int prev, int n, int maxValue, int size){
    if(size == n) return 1;

    int ans = 0;

    for(int i = 1; i <= maxValue; i++){
        if(i % prev == 0) {
            ans += helper(i, n, maxValue, size + 1);
        }
    }

    return ans;
}

int helperDp(int prev, int n, int maxValue, int size, vector<vector<int>> &dp){
    if(size == n) return 1;
    if(dp[prev][size] != -1) return dp[prev][size];

    int ans = 0;

    for(int i = 1; i <= maxValue; i++){
        if(i % prev == 0) {
            ans += helperDp(i, n, maxValue, size + 1, dp);
        }
    }

    return dp[prev][size] = ans;
}


// wrong 
int helperTab(int n, int maxValue){

    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(maxValue + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= maxValue; i++) dp[i][n] = 1;

    for (int size = n - 1; size >= 1; size--) {
        for (int prev = 1; prev <= maxValue; prev++) {
            long long ans = 0;
            for (int k = prev; k <= maxValue; k += prev) {
                ans = (ans + dp[k][size + 1]) % MOD;
            }
            dp[prev][size] = ans;
        }
    }
    return dp[1][1];
}


// this is also give TLE
const int MOD = 1e9 + 7;

int helperTab2(int n, int maxValue) {
    vector<vector<int>> dp(n + 1, vector<int>(maxValue + 1, 0));

    // Base case: At size = 1, we can start with any number 1 to maxValue
    for (int val = 1; val <= maxValue; val++) {
        dp[1][val] = 1;
    }

    // Build DP table for sizes from 2 to n
    for (int size = 2; size <= n; size++) {
        for (int prev = 1; prev <= maxValue; prev++) {
            // Try all multiples of prev
            for (int next = prev; next <= maxValue; next += prev) {
                dp[size][next] = (dp[size][next] + dp[size - 1][prev]) % MOD;
            }
        }
    }

    // Sum all sequences of length n
    int ans = 0;
    for (int val = 1; val <= maxValue; val++) {
        ans = (ans + dp[n][val]) % MOD;
    }

    return ans;
}


// this is final answer 
const int MOD = 1e9 + 7, MAX_N = 1e4 + 10,
          MAX_P = 15;  // There are up to 15 prime factors
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N];  // List of prime factor counts
int sieve[MAX_N];       // Minimum prime factor

class Solution {
public:
    Solution() {
        if (c[0][0]) {
            return;
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i;
                }
            }
        }
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long long mul = 1;
            for (int p : ps[x]) {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return ans;
    }
};



int idealArray(int n, int maxValue){
    int ans = 0;
    vector<vector<int>> dp(maxValue + 1, vector<int>(n + 1, -1));
    // ans = helper(1, n, maxValue, 0);
    // ans = helperDp(1, n, maxValue, 0, dp);
    ans = helperTab2(n, maxValue);
    return ans;
}

int main(){
    int n = 2;
    int maxValue = 5;
    cout << idealArray(n, maxValue) << endl;
    return 0;
}