#include <bits/stdc++.h>
using namespace std;

/*
   72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

/* To solve this question we have to use concept of string matching concept 
   if character matches
    Then return f(i - 1, j - 1)  // if they matches we no need to think of that
   if not matches then i have three option
      1. delete
      2. replace
      3. insert
      and take min(all of these)

*/

int editDistance(int i, int j, string &s, string &t){
    // base case
    if(j < 0) return i + 1;
    if(i < 0) return j + 1;

    // if s got exhausted means over so to convert Empty s to t we required insert remaining of j + 1 element
    // likewise if t exhausted then we have to delete remaining elements of s to convert s to t

    // if matches 
    if(s[i] == t[j]) return editDistance(i - 1, j - 1, s, t);

    // if not matches
    return min(
        1 + editDistance(i - 1, j, s, t), // if delete then i reduce but not j
        min(
            1 + editDistance(i - 1, j - 1, s, t), // if replace then both same and reduce both i and  j
            1 + editDistance(i, j - 1, s, t)  // if insert then we will insert next to i, so i will not reduce but j will reduce
        )
    );
}

// memoization
int editDistanceDp(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    // base case
    if(j < 0) return i + 1;
    if(i < 0) return j + 1;
    if(dp[i][j] != -1) return dp[i][j];

    // if s got exhausted means over so to convert Empty s to t we required insert remaining of j + 1 element
    // likewise if t exhausted then we have to delete remaining elements of s to convert s to t

    // if matches 
    if(s[i] == t[j]) return dp[i][j] = editDistanceDp(i - 1, j - 1, s, t, dp);

    // if not matches
    return dp[i][j] = min(
        1 + editDistanceDp(i - 1, j, s, t, dp), // if delete then i reduce but not j
        min(
            1 + editDistanceDp(i - 1, j - 1, s, t, dp), // if replace then both same and reduce both i and  j
            1 + editDistanceDp(i, j - 1, s, t, dp)  // if insert then we will insert next to i, so i will not reduce but j will reduce
        )
    );
}

// for tabulation we have to follow 1 based indexing
// Tabulation
int editDistanceTab(int n, int m, string &s, string &t){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];

            // if not matches
            else{
                dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]));
            }
        }
    }
    return dp[n][m];
}

//space optimization
int editDistanceSpace(int n, int m, string &s, string &t){
    vector<int> cur(m + 1, 0), prev(m + 1, 0);
    for(int j = 0; j <= m; j++) prev[j] = j;


    for(int i = 1; i <= n; i++){
        cur[0] = i; // for every row cur[0] will be i 
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]) cur[j] = prev[j - 1];

            // if not matches
            else{
                cur[j] = min(1 + prev[j], min(1 + prev[j - 1], 1 + cur[j - 1]));
            }
        }
        prev = cur;
    }
    return prev[m];
}

// we cannot to space optimize it in 1 1d array we it needed previous of both cur and prev

int main(){
    string a = "intention";
    string b = "execution";
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << editDistance(n - 1, m - 1, a, b) << endl;
    cout << editDistanceDp(n - 1, m - 1, a, b, dp) << endl;
    cout << editDistanceTab(n, m, a, b) << endl;
    cout << editDistanceSpace(n, m, a, b) << endl;
    return 0;
}