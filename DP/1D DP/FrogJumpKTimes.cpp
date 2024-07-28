#include <bits/stdc++.h>
using namespace std;


int frogJump(int ind, vector<int> &height,vector<int> &dp,int k){
    // if(n == 0) return 0;
    // if(dp[n] != -1) return dp[n];
    // int res = INT_MAX;
    // int jump = INT_MAX;
    // for(int i = 1; i < k; i++){
    //     if(n - i >= 0) jump = frogJump(n - i,jump,dp,k);
    //     res = min(res,jump);
    // }
    // return dp[n] = res;

    if (ind == 0) return 0;
    
    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1) return dp[ind];
    
    int mmSteps = INT_MAX;
    
    // Loop to try all possible jumps from '1' to 'k'
    for (int j = 1; j <= k; j++) {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0) {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = frogJump(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    
    // Store the minimum cost for this index in the dp array and return it.
    return dp[ind] = mmSteps;
}
int main(){
    int n = 5;
    vector<int> jump = {10,20,50,80,30};
    vector<int> dp(n + 1, -1);
    cout<<frogJump(n - 1,jump,dp,3);
    return 0;
}


// same quetion LeetCode 55 : Jump game
