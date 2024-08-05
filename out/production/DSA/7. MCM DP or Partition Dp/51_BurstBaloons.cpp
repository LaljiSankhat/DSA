#include <bits/stdc++.h>
using namespace std;


/*
    312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on
it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely. 

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10
 
Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

/*
    Here if we first the baloon then we get coin as (prev * cur * next) coins. but after bursting out we dont have the 
    baloon so we dont have to consider that or remove that.
    here we can not make partitions like previous quesion because here we have to access the prev elements coin.
*/

/*
    To solve this we have to go bottom to up 
    let consider [b1, b2, b3, b4, b5, b6] is the coins for 6 baloons 
    consider this array in range of "i to j" indexs
    let assume that b4 is the last guy who is bursted, since the b4 is last guy is bursted we ca say 
    that outer points of range will be the prev and next guys so cost is (i - 1) * (j + 1) * (coin of b4)
    now we can solve the (b1, b2, b3) and (b5, b6) as independently in same logic because in next step we go for 
    second last burst where possible configurations can be (b1, b4), (b2, b4), (b3, b4), (b5, b4) and (b6, b4)
    so all depends on the b4 so we can solve it independently
*/


int burstBaloons(int i, int j, vector<int> &nums){
    if(i > j) return 0;

    // explore all possibilities
    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + burstBaloons(i, ind - 1, nums) + burstBaloons(ind + 1, j, nums);
        maxi = max(maxi, cost);
    }
    
    return maxi;
}

// memoizations
int burstBaloonsDp(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // explore all possibilities
    int maxi = INT_MIN;
    for(int ind = i; ind <= j; ind++){
        int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + burstBaloonsDp(i, ind - 1, nums, dp) + burstBaloonsDp(ind + 1, j, nums, dp);
        maxi = max(maxi, cost);
    }
    
    return dp[i][j] = maxi;
}

// tabulation
int burstBaloonsTab(int n, vector<int> &nums){
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Loops
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            if(i > j) continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
    
}

int maxCoins(vector<int> &nums){
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    // return burstBaloons(1, n, nums);

    // memoization
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return burstBaloonsDp(1, n, nums, dp);

    // tabulation
    return burstBaloonsTab(n, nums);
}
int main(){
    vector<int> nums = {3,1,5,8};
    int n = nums.size();
    cout << maxCoins(nums) << endl;
    return 0;

}