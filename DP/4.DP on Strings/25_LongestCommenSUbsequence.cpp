#include <bits/stdc++.h>
using namespace std;


/* 
   LeetCode : 1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. 
If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some 
characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings. 

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0. 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

/* in all dp on string question there is two possibilities either match or not match */
/* Here we have to shift indexex in right so every index represents index - 1
   this will help us in tabulation solution becuase we have to right base cases where we can
   not represent dp[-1] so we shift the index */

int longestCommenSubsequence(int i1, int i2, string &s1, string &s2){
    // Base case
    // if any index goes to -1 then string is over and we cannot find commen subsequence so return 0
    if(i1 == 0 || i2 == 0) return 0;


    // if matching then simple jump to previos index and +1
    if(s1[i1 - 1] == s2[i2 - 1]) return (1 + longestCommenSubsequence(i1 - 1, i2 - 1, s1, s2));

    // if not Matches so we two cases 1. reduce string1 2. reduce string 2
    return max(longestCommenSubsequence(i1 - 1, i2, s1, s2), longestCommenSubsequence(i1, i2 - 1, s1, s2));
}

// memoization
int longestCommenSubsequenceDp(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp){
    // Base case
    if(i1 == 0 || i2 == 0) return 0;
    if(dp[i1][i2] != -1) return dp[i1][i2];

    // if matching then simple jump to previos index and +1
    if(s1[i1 - 1] == s2[i2 - 1]) return dp[i1][i2] = (1 + longestCommenSubsequenceDp(i1 - 1, i2 - 1, s1, s2, dp));

    // if not Matches so we two cases 1. reduce string1 2. reduce string 2
    return dp[i1][i2] = max(longestCommenSubsequenceDp(i1 - 1, i2, s1, s2, dp), longestCommenSubsequenceDp(i1, i2 - 1, s1, s2, dp));
}

//Tabulation
int longestCommenSubsequenceTab(int n, int m, string &s1, string &s2){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    //base
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;

    //Loops
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // if not Matches so we two cases 1. reduce string1 2. reduce string 2
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

//spave optimization
int longestCommenSubsequenceSpace(int n, int m, string &s1, string &s2){
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    //base
    for(int i = 0; i <= n; i++) prev[0] = 0;

    //Loops
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1];

            // if not Matches so we two cases 1. reduce string1 2. reduce string 2
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[m];
}


int main(){
    string s1 ="abcde";
    string s2 ="ace";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << longestCommenSubsequence(n, m, s1, s2) << endl;
    cout << longestCommenSubsequenceDp(n, m, s1, s2, dp) << endl;
    cout << longestCommenSubsequenceTab(n, m, s1, s2) << endl;
    cout << longestCommenSubsequenceSpace(n, m, s1, s2) << endl;
    return 0;
}