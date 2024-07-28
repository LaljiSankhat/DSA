#include <bits/stdc++.h>
using namespace std;

/* 
   LeetCode : 1092. Shortest Common Supersequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
 If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) 
results in the string s. 

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa" 

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

/* To solve this let 
    s1 = "brute" 
    s2 = "groot"
    in both of them "rt" is common so why we writing it twice, just write only once 
    so length of superSeuence = s1.size() + s2.size() - lcs(s1, s2);
*/

int longestCommenSubsequenceTab(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){

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

string printLcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int len = longestCommenSubsequenceTab(n, m, s1, s2, dp);

    string ans = "";
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) {
            ans += s1[i - 1];
            i--;
        }
        else{
            ans += s2[j - 1];
            j--;
        }
    }

    while(i > 0){
        ans += s1[i - 1];
        i--;
    }
    while(j > 0){
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string a = "abac";
    string b = "cab";
    cout << printLcs(a, b) << endl;
    return 0;
}