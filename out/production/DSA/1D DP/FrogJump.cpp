#include <bits/stdc++.h>
using namespace std;


int frogJump(int n, vector<int> &jump, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int left = frogJump(n - 1, jump, dp) + abs(jump[n] - jump[n - 1]);
    int right = INT_MAX;    
    if(n > 1){
        right = frogJump(n - 2, jump, dp) + abs(jump[n] - jump[n - 2]);
    }
    return dp[n] = min(left,right);  
}

// space optimised 
int frogJumpSpaceOptimised(int n, vector<int> &jump){
    int prev2 = 0;
    int prev1 = abs(jump[1] - jump[0]);
    for(int i = 2; i <= n; i++){
        int left = prev1 + abs(jump[i] - jump[i - 1]);
        // int right = INT_MAX;
        int right = prev2 + abs(jump[i] - jump[i - 2]);
        int res = min(left,right);
        prev2 = prev1;
        prev1 = res;
    }
    return prev1;
}

int main(){
    int n = 6;
    vector<int> jump = {30,10,60,10,60,50};
    vector<int> dp(n + 1, -1);
    cout<< frogJump(n - 1,jump,dp)<<endl;
    cout<< frogJumpSpaceOptimised(n - 1,jump)<<endl;
    return 0;
}