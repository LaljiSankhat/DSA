#include <bits/stdc++.h>
using namespace std;

/*
   44. Wildcard Matching 

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial). 

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'. 

Constraints:
0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

/* Here if we see ? is as same as characters are matched  but in case of *  we have to think
   so we have two case
   1. if * is empty string so reduce i but not j
   2. * matches with character so we reduce the j but not i because * will match another characters also 
*/

bool wildcardMatching(int i, int j, string &p, string &s){
    // base cases
    if(i < 0 && j < 0) return true; // if both exhausted then return true
    if(i < 0 && j >= 0) return false; // some comparison still remains 
    if(j < 0 && i >= 0){
        for(int l = 0; l <= i; l++){
            if(p[l] != '*') return false;
        }
        return true;
    }


    // if matches
    if(p[i] == s[j] || p[i] == '?') return wildcardMatching(i - 1, j - 1, p, s);
    // if *
    if(p[i] == '*') return wildcardMatching(i - 1, j, p, s) || wildcardMatching(i, j - 1, p, s);

    // if not matches then
    return false;
}

//memoization
bool wildcardMatchingDp(int i, int j, string &p, string &s, vector<vector<int>> &dp){
    // base cases
    if(i < 0 && j < 0) return true; // if both exhausted then return true
    if(i < 0 && j >= 0) return false; // some comparison still remains 
    if(j < 0 && i >= 0){
        for(int l = 0; l <= i; l++){
            if(p[l] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];


    // if matches
    if(p[i] == s[j] || p[i] == '?') return dp[i][j] = wildcardMatchingDp(i - 1, j - 1, p, s, dp);
    // if *
    if(p[i] == '*') return dp[i][j] = wildcardMatchingDp(i - 1, j, p, s, dp) || wildcardMatchingDp(i, j - 1, p, s, dp);

    // if not matches then
    return dp[i][j] = false;
}

// Tabulation
bool wildcardMatchingTab(int n, int m, string &p, string &s){
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int l = 1; l <= i; l++){
            if(p[l - 1] != '*'){
                flag= false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else dp[i][j] = false;
        }
    }

    return dp[n][m];
}

// Space optimization
bool wildcardMatchingSpace(int n, int m, string &p, string &s){
    vector<bool> cur(m + 1, 0), prev(m + 1, 0);

    prev[0] = true;

    for(int i = 1; i <= n; i++){
        bool flag = true; // this code here becaus we have to check for every i
        for(int l = 1; l <= i; l++){
            if(p[l - 1] != '*'){
                flag= false;
                break;
            }
        }
        cur[0] = flag;
        for(int j = 1; j <= m; j++){
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                cur[j] = prev[j - 1];
            else if (p[i - 1] == '*')
                cur[j] = prev[j] || cur[j - 1];
            else cur[j] = false;
        }
        prev = cur;
    }

    return prev[m];
}

int main(){
    string p = "*";
    string s= "aa";
    int n = p.size();
    int m = s.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << wildcardMatching(n - 1, m - 1, p, s) << endl;
    cout << wildcardMatchingDp(n - 1, m - 1, p, s, dp) << endl;
    cout << wildcardMatchingTab(n, m, p, s) << endl;
    cout << wildcardMatchingSpace(n, m, p, s) << endl;
    return 0;
}