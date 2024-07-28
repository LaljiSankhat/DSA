#include <bits/stdc++.h>
using namespace std;


/*
    1547. Minimum Cost to Cut a Stick
Given a wooden stick of length n units. The stick is labelled from 0 to n. 
For example, a stick of length 6 is labelled as follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts.
When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is 
the length of the stick before the cut). Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts.

Example 1:

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 
(i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a 
rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20. Rearranging the cuts to be [3, 5, 1, 4] for
example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 
which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
All the integers in cuts array are distinct.
*/

/*
    To solve this question first we have to sort the array.
    we will add 0 in front of array and arr.length() at the end of array which will help us to find the cost
    we make call with f(i, j)  i = 1 and j = n - 1. 
    we can make cut between i to j so we will run a loop to cut
    if we cut at a index ind then cost = cuts[j + 1] - cuts[i - 1] + f(i, ind - 1) + f(ind + 1, j);
    then we simply return the minimum answer. 
*/

int minCostToCutStick(int i, int j, vector<int> &cuts){
    if(i > j) return 0;

    // all posible ways
    int mini = 1e9;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j + 1] - cuts[i - 1] + minCostToCutStick(i, ind - 1, cuts) + minCostToCutStick(ind + 1, j, cuts);
        mini = min(mini, cost);
    }

    return mini;
}



// Memoization
int minCostToCutStickDp(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // all posible ways
    int mini = 1e9;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j + 1] - cuts[i - 1] + minCostToCutStickDp(i, ind - 1, cuts, dp) + minCostToCutStickDp(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

// Tabulation
int minCostToCutStickTab(vector<int> &cuts, int l){
    vector<vector<int>> dp(l, vector<int>(l, 0));

    int n = cuts.size();

    for(int i = n - 2; i >= 1; i--){
        for(int j = 1; j < n - 1; j++){
            int mini = 1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n - 2];
}

int minCost(vector<int> &cuts, int l){
    cuts.push_back(l);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    // return minCostToCutStick(1, n - 2, cuts);

    // for tabulation
    // vector<vector<int>> dp(l + 1, vector<int>(l + 1, -1));
    // return minCostToCutStickDp(1, n - 2, cuts, dp);

    // Tabulation
    return minCostToCutStickTab(cuts, l);
}


int main(){
    vector<int> cuts = {5,6,1,4,2};
    int l = 9;
    cout << minCost(cuts, l) << endl;
    return 0;
}