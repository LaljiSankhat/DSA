#include <bits/stdc++.h>
using namespace std;

/* this question same as previos but here we have to find substring the only difference is substring is
   must be consicutive. */

/* to solve we use to fill dp array where if they match then we go to previous what is longest common string
   ans add 1 into it. if they dont match then we cant do anything */

int longestCommenSubStringTab(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    int ans = 0;

    // Loops
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            // if matching then add 1 into previos and assign it
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            

            /// else we do nothing
            else dp[i][j] = 0;
        }
    }

    return ans;
}

// space optimization
int longestCommenSubStringSpace(int n, int m, string &s1, string &s2)
{
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;

    // Loops
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // if matching then add 1 into previos and assign it
            if (s1[i - 1] == s2[j - 1]){
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            }
            // else we do nothing
            else cur[j] = 0;
        }
        prev = cur;
    }

    return ans;
}

int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.size();
    int m = s2.size();
    cout << longestCommenSubStringTab(n, m, s1, s2) << endl;
    cout << longestCommenSubStringSpace(n, m, s1, s2) << endl;
    return 0;
}