#include <bits/stdc++.h>
using namespace std;

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the
maximum total value in the knapsack.Note: Unlike 0/1 knapsack, you are allowed to break the item here.

Example 1:

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000
Explanation:
Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item
 with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80,
 so the total value becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack.


Example 2:

Input:
N = 2, W = 50
value[] = {60,100}
weight[] = {10,20}
Output:
160.000000
Explanation:
Take both the items completely, without breaking.
Total maximum value of item we can have is 160.00 from the given capacity of sack.
Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class
and size N and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= W <= 109
1 <= valuei, weighti <= 104
*/

// Recursion
int knapsack(int i, vector<int> &w, vector<int> &v, int maxWeight)
{
  if (maxWeight == 0)
    return 0;
  if(i == 0){
    if(maxWeight >= w[i]) return v[i];
    else return INT_MIN;
  }

  int notTake = knapsack(i - 1, w, v, maxWeight);
  int take = 0;
  if (maxWeight >= w[i])
  {
    take = v[i] + knapsack(i - 1, w, v, maxWeight - w[i]);
  }

  return max(notTake, take);
}

// memoization
/* for memoization we can see that changing states are index and maxWeight so we have to declare 2D dp*/

int knapsackDp(int i, vector<int> &w, vector<int> &v, int maxWeight, vector<vector<int>> &dp)
{
  if (maxWeight == 0)
    return 0;
  if(i == 0){
    if(maxWeight >= w[i]) return v[i];
    else return INT_MIN;
  }
  if (dp[i][maxWeight] != -1)
    return dp[i][maxWeight];

  int notTake = knapsackDp(i - 1, w, v, maxWeight, dp);
  int take = 0;
  if (maxWeight >= w[i])
  {
    take = v[i] + knapsackDp(i - 1, w, v, maxWeight - w[i], dp);
  }

  return dp[i][maxWeight] = max(notTake, take);
}

// Tabulation
int knapsackTab(int n, vector<int> &w, vector<int> &v, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0 ));
  // cover base cases
  // weights == 0
  // for (int i = 0; i < n; i++)
  //   dp[i][0] = 0;
  for(int i = w[0]; i <= maxWeight; i++) dp[0][i] = v[0];

  // loops for changing states index and maxweights
  for (int i = 1; i < n; i++)
  {
    for (int W = 0; W <= maxWeight; W++)
    {
      int notTake = dp[i - 1][W];
      int take = INT_MIN;
      if (W >= w[i])
      {
        take = v[i] + dp[i - 1][W - w[i]];
      }
      dp[i][W] = max(notTake, take);
    }
  }
  return dp[n - 1][maxWeight];
}

// space optimization
int knapsackSpace(int n, vector<int> &w, vector<int> &v, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);
  for(int i = w[0]; i <= maxWeight; i++) prev[i] = v[0];

  // loops for changing states index and maxweights
  for (int i = 1; i < n; i++)
  {
    for (int W = 0; W <= maxWeight; W++)
    {
      int notTake = prev[W];
      int take = INT_MIN;
      if (W >= w[i])
      {
        take = v[i] + prev[W - w[i]];
      }
      cur[W] = max(notTake, take);
    }
    prev = cur;
  }
  return prev[maxWeight];
}

// we still optimize it by removing cur
/* in finding cur we require left part of index we dont require right part so we can overwrtie prev from right to left
using let part of cur  */

int knapsackSpace2(int n, vector<int> &w, vector<int> &v, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0);
  for(int i = w[0]; i <= maxWeight; i++) prev[i] = v[0];

  // loops for changing states index and maxweights
  for (int i = 1; i < n; i++)
  {
    for (int W = maxWeight; W >= 0; W--)
    {
      int notTake = prev[W];
      int take = INT_MIN;
      if (W >= w[i])
      {
        take = v[i] + prev[W - w[i]];
      }
      prev[W] = max(notTake, take);
    }
  }
  return prev[maxWeight];
}


int main()
{
  vector<int> weights = {10, 20, 30};
  vector<int> values = {60, 100, 120};
  int maxWeight = 50;
  int n = weights.size();
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  cout << knapsack(weights.size() - 1, weights, values, maxWeight) << endl;
  cout << knapsackDp(weights.size() - 1, weights, values, maxWeight, dp) << endl;
  cout << knapsackTab(n, weights, values, maxWeight) << endl;
  cout << knapsackSpace(n, weights, values, maxWeight) << endl;
  cout << knapsackSpace2(n, weights, values, maxWeight) << endl;
  return 0;
}