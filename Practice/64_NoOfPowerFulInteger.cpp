#include <bits/stdc++.h>
using namespace std;


// leetcode 2999. Count the Number of Powerful Integers


// here we have to use digit dp 
// pending 


long long dp[20][2];

long long solve(string num, string s, int tight, int n, int limit){
    if(num.length() < s.length()) return 0;
    if(dp[n][tight] != -1) return dp[n][tight];

    int ub = tight ? num[num.length() - n] - '0' : limit;
    long long ans = 0;

    if(n == 1){
        int a = s[s.length() - n] - '0';
        if(a > ub){
            return 0LL;
        }
        return 1LL;
    }
    if(n <= s.length()){
        if(tight){
            int a = s[s.length() - n]- '0';
            if(a > ub){
                return 0LL;
            } else if(a == ub){
                ans = (long long)(ans + solve(num, s, 1, n - 1, limit));
                return ans;
            } else {
                return 1LL;
            }
        } else {
            return 1LL;
        }
    } else {
        for(int i = 0; i <= ub && i <= limit; i++){
            ans = (long long)(ans + solve(num, s, (tight & (i == ub)), n - 1, limit));
        }
    }

    return dp[n][tight] = ans;
}

long long numberOfPowerfulIntegers(long long start, long long finish, int limit, string s){
    string r = to_string(finish);
    string l = to_string(start - 1);
    memset(dp, -1, sizeof(dp));
    long long a = solve(r, s, 1, r.length(), limit);
    memset(dp, -1, sizeof(dp));
    long long b = solve(l, s, 1, l.length(), limit);
    return max(0LL, a - b);
}



int main(){
    int start = 1;
    int finish = 6000;
    int limit = 4;
    string s = "124";
    cout << numberOfPowerfulIntegers(start, finish, limit, s) << endl;
    return 0;
}