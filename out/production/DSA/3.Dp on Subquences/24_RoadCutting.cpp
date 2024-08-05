#include <bits/stdc++.h>
using namespace std;

/*
  Problem statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost 
associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.
2. The sum of the pieces cut should be equal to ‘N’.
3. Consider 1-based indexing.

Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation of sample input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
*/

/* this is also same as previos questions where we can divide a rod into similar length and we
 get similar amount from that */
int maxCost(int i, int roadLength, vector<int> &price){
    if(i == 0) return price[0] * roadLength;

    int notTake = maxCost(i - 1, roadLength, price);
    int take = -1e9;
    if((i + 1) <= roadLength) take = price[i] + maxCost(i, roadLength - (i + 1), price);

    return max(notTake, take);
}

// memoization
int maxCostDp(int i, int roadLength, vector<int> &price, vector<vector<int>> &dp){
    if(i == 0) return price[i] * roadLength;
    if(dp[i][roadLength] != -1) return dp[i][roadLength];

    int notTake = maxCostDp(i - 1, roadLength, price, dp);
    int take = -1e9;
    if((i + 1) <= roadLength) take = price[i] + maxCostDp(i, roadLength - (i + 1), price, dp);

    return dp[i][roadLength] = max(notTake, take);
}

// Tabulation
int maxCostTab(int n, int roadLength, vector<int> &price){
    vector<vector<int>> dp(n, vector<int>(roadLength + 1, 0));

    for(int i = 1; i <= roadLength; i++) dp[0][i] = price[0] * i;

    for(int i = 1; i < n; i++){
        for(int r = 1; r <= roadLength; r++){
            int notTake = dp[i - 1][r];
            int take = -1e9;
            if ((i + 1) <= r)
                take = price[i] + dp[i][r - (i + 1)];
            dp[i][r] = max(notTake, take);
        }
    }

    return dp[n - 1][roadLength];
    
}

// space optimization
int maxCostSpace(int n, int roadLength, vector<int> &price){
    vector<int> cur(roadLength + 1, 0), prev(roadLength + 1, 0);

    for(int i = 1; i <= roadLength; i++) prev[i] = price[0] * i;

    for(int i = 1; i < n; i++){
        for(int r = 1; r <= roadLength; r++){
            int notTake = prev[r];
            int take = -1e9;
            if ((i + 1) <= r)
                take = price[i] + cur[r - (i + 1)];
            cur[r] = max(notTake, take);
        }
        prev = cur;
    }

    return prev[roadLength];
    
}

int maxCostSpace2(int n, int roadLength, vector<int> &price){
    vector<int> prev(roadLength + 1, 0);

    for(int i = 1; i <= roadLength; i++) prev[i] = price[0] * i;

    for(int i = 1; i < n; i++){
        for(int r = 1; r <= roadLength; r++){
            int notTake = prev[r];
            int take = -1e9;
            if ((i + 1) <= r)
                take = price[i] + prev[r - (i + 1)];
            prev[r] = max(notTake, take);
        }
    }

    return prev[roadLength];
    
}

int main(){
    vector<int> price = {2,5,7,8,10};
    int roadLength = 5;
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(roadLength + 1, -1));
    cout << maxCost(n - 1, roadLength, price) << endl;
    cout << maxCostDp(n - 1, roadLength, price, dp) << endl;
    cout << maxCostTab(n, roadLength, price) << endl;
    cout << maxCostSpace(n, roadLength, price) << endl;
    cout << maxCostSpace2(n, roadLength, price) << endl;
    return 0;
}