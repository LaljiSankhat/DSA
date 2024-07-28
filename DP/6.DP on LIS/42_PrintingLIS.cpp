#include <bits/stdc++.h>
using namespace std;

/* extention of previos question */

int longestIncreasingSubsequenceTab(int n, vector<int> &nums){
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // no need base case becuase all things are zero
    for(int i = n - 1; i >= 0; i--){
        for(int pi = i - 1; pi >= -1; pi--){
            int notTake = dp[i + 1][pi + 1];
            int take = 0;
            if (pi == -1 || nums[pi] < nums[i])
                take = 1 + dp[i + 1][i + 1];

            dp[i][pi + 1] = max(take, notTake);
        }
    }

    return dp[0][-1 + 1];;
}

// space Optimization
int longestIncreasingSubsequenceSpace(int n, vector<int> &nums){
    vector<int> cur(n + 1, 0), next(n + 1, 0);
    // no need base case becuase all things are zero
    for(int i = n - 1; i >= 0; i--){
        for(int pi = i - 1; pi >= -1; pi--){
            int notTake = next[pi + 1];
            int take = 0;
            if (pi == -1 || nums[pi] < nums[i])
                take = 1 + next[i + 1];

            cur[pi + 1] = max(take, notTake);
        }
        next = cur;
    }

    return next[-1 + 1];;
}

// method 2 Tabulation
/* We define a dp[n] array then we start two loops and check weather the jth elem is part of LIS of ith elem if 
   yes then we check if it is greater then we update it*/
/* here dp[i] indicates the LIS ending at i */

int longestIncreasingSubsequenceTab2(int n, vector<int> &nums){
    vector<int> dp(n, 1);
    int maxi = 0;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i]){ // this is valid, this can be part of LIS
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

// Printing the LIS
/* To print the LIS we have to create hash or Backtrack array that will store the prev index of LIS this will
    help us to backtrack. all of these we will doing in tab2 solution */

vector<int> printLIS(int n, vector<int> &nums){
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int lastIndex = 0;

    for(int i = 1; i < n; i++){
        hash[i] = i;
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]){ // this is valid, this can be part of LIS
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    int ind = 1;
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());

    return lis;
}


int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();
    cout << longestIncreasingSubsequenceTab(n, nums) << endl;
    cout << longestIncreasingSubsequenceSpace(n, nums) << endl;
    cout << longestIncreasingSubsequenceTab2(n, nums) << endl;
    // cout << printLIS(n, nums) << endl;
    vector<int> lis = printLIS(n, nums);
    for(auto a : lis) cout << a << " ";
    return 0;
}