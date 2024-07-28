#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubString(string s){
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0;
    vector<int> a(2, 0);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if(dp[i][j] > ans){
                    a[0] = i;
                    a[1] = j;
                    ans = dp[i][j];
                }
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout<<endl;
    // }

    string l = "";
    int i = a[0] - 1;
    int j = a[1] - 1;
    int st = i - ans;
    for(int as = st; as <= i; as++){
        l += (char)s[as];
    }

    return l;
}

int main(){
    string s = "babad";
    cout << longestPalindromicSubString(s) << endl;
    // vector<int> ans = longestPalindromicSubString(s);
    // cout << ans[0] << endl;
    // cout << ans[1] << endl;
    return 0;
}