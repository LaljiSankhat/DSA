#include <bits/stdc++.h>
using namespace std;

/*
  Question is as same as 25 but here we have to print the longest commen subsequence
*/

/* to solve this question we have to use DP array generated in Q.25  */

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
    for(int i = 0; i < len; i++) ans += '$';

    int index = len - 1;
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            ans[index--] = s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    return ans;
}

int main(){
    string s1 ="abcde";
    string s2 ="ace";
    int n = s1.size();
    int m = s2.size();
    cout << printLcs(s1, s2) << endl;
    return 0;
}