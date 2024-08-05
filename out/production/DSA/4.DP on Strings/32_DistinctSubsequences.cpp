#include <bits/stdc++.h>
using namespace std;

/*
   115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer. 

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s. 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

/* To solve we have two options
   1. matches
        Then we have two cases either i will take it or not take it. sum both of them and return it
   2. not matche
        Then we go back in first string and return the answer 

*/

int distinctSubsequences(int i, int j, string &s, string &t){
    // Base case
    if(j < 0) return 1;
    if(i < 0) return 0;

    // if matches
    if(s[i] == t[j]){
        return distinctSubsequences(i - 1, j - 1, s, t) + distinctSubsequences(i - 1, j, s, t);
    }

    return  distinctSubsequences(i - 1, j, s, t); 
}

// memoization
int distinctSubsequencesDp(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    // Base case
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // if matches
    if(s[i] == t[j]){
        return dp[i][j] = distinctSubsequencesDp(i - 1, j - 1, s, t, dp) + distinctSubsequencesDp(i - 1, j, s, t, dp);
    }

    return dp[i][j] = distinctSubsequencesDp(i - 1, j, s, t, dp);    
}

//Tabulation
int distinctSubsequencesTab(int n, int m, string &s, string &t){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= m; j++) dp[0][j] = 0; 
    // j will start from 1 not 0 because if start with 0 then it will be overwrite on dp[i][0] case for i == 0

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

// space optimization
int distinctSubsequencesSpace(int n, int m, string &s, string &t){
    vector<int> cur(m + 1, 0), prev(m + 1, 0);

    prev[0] = 1; 
    cur[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s[i - 1] == t[j - 1]){
                cur[j] = prev[j - 1] + prev[j];
            }
            else{
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }

    return prev[m];
}

// space optimization into 1 1d array
int distinctSubsequencesSpace2(int n, int m, string &s, string &t){
    vector<int> prev(m + 1, 0);

    prev[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            if (s[i - 1] == t[j - 1]){
                prev[j] = prev[j - 1] + prev[j];
            }
        }
    }
    
    return prev[m];
}


int main(){
    string a = "babgbag";
    string b = "bag";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << distinctSubsequences(n - 1, m - 1, a, b) << endl;
    cout << distinctSubsequencesDp(n - 1, m - 1, a, b, dp) << endl;
    cout << distinctSubsequencesTab(n, m, a, b) << endl;
    cout << distinctSubsequencesSpace(n, m, a, b) << endl;
    cout << distinctSubsequencesSpace2(n, m, a, b) << endl;
    return 0;
}