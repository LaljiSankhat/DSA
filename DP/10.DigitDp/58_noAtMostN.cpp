#include <bits/stdc++.h>
using namespace std;


// leetcode 902 . Numbers At Most N Given Digit Set
// here we have to use digit dp

int solve(string &s, int pos, bool tight, vector<string> &digits, vector<vector<vector<int>>>& dp, bool used){
    if(pos == s.length()) return used ? 1 : 0;
    if (dp[pos][tight][used] != -1) {
        return dp[pos][tight][used];
    }

    int ub = tight ? s[pos] - '0' : 9;
    int ans = 0;   

    for(int i = 0; i < digits.size(); i++){
        int digit = digits[i][0] - '0'; // Convert string digit to integer

        // If the current digit is greater than the upper bound, break
        if (digit > ub) {
            break;
        }

        // Recursively call the function for the next position
        ans += solve(s, pos + 1, tight && (digit == ub), digits, dp, 1);
    }

    if (!used) {
        ans += solve(s, pos + 1, tight && (0 == ub), digits, dp, 0); // Do not use any digit yet
    }

    return dp[pos][tight][used] = ans;
}

int atMostNGivenDigits(vector<string> &digits, int n){
    string num = to_string(n);
    int m = num.length();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(2, vector<int>(2, -1)));

    return solve(num, 0, 1, digits, dp, 0);
}

int main(){
    vector<string> digits = {"1", "3", "5", "7"};
    int n = 100;
    cout << atMostNGivenDigits(digits, n) << endl; // Output: 20 (1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77)
    return 0;
}