#include <bits/stdc++.h>
using namespace std;

/*
  Problem statement
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit. 
You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.

Expected Time Complexity:
Try to solve this in O(n*w).

Constraints
1 <= n <= 10^3
1 <= w <= 10^3
1 <= profit[i] , weight[i] <= 10^8

Time Limit: 1 sec
*/
/* this same as knapsack but here we can steal any bags multiple times so it's concept is as same as previos 2 to 3 question */

int knapsack(int i, vector<int> &w, vector<int> &v, int maxWeight)
{
  if (maxWeight == 0)
    return 0;
  if(i == 0) return v[i] * ((int)(maxWeight / w[0]));
  

  int notTake = knapsack(i - 1, w, v, maxWeight);
  int take = 0;
  if (maxWeight >= w[i])
  {
    take = v[i] + knapsack(i, w, v, maxWeight - w[i]);
  }

  return max(notTake, take);
}

int knapsackDp(int i, vector<int> &w, vector<int> &v, int maxWeight, vector<vector<int>> &dp)
{
  if (maxWeight == 0)
    return 0;
  if(i == 0) return v[i] * ((int)(maxWeight / w[0]));
  if (dp[i][maxWeight] != -1)
    return dp[i][maxWeight];

  int notTake = knapsackDp(i - 1, w, v, maxWeight, dp);
  int take = 0;
  if (maxWeight >= w[i])
  {
    take = v[i] + knapsackDp(i, w, v, maxWeight - w[i], dp);
  }

  return dp[i][maxWeight] = max(notTake, take);
}

// Tabulation
int knapsackTab(int n, vector<int> &w, vector<int> &v, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0 ));
  for(int i = w[0]; i <= maxWeight; i++) dp[0][i] = v[0] * ((int)(i / w[0]));

  // loops for changing states index and maxweights
  for (int i = 1; i < n; i++)
  {
    for (int W = 0; W <= maxWeight; W++)
    {
      int notTake = dp[i - 1][W];
      int take = INT_MIN;
      if (W >= w[i])
      {
        take = v[i] + dp[i][W - w[i]];
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
  for(int i = w[0]; i <= maxWeight; i++) prev[i] = v[0] * ((int)(i / w[0]));

  // loops for changing states index and maxweights
  for (int i = 1; i < n; i++)
  {
    for (int W = 0; W <= maxWeight; W++)
    {
      int notTake = prev[W];
      int take = INT_MIN;
      if (W >= w[i])
      {
        take = v[i] + cur[W - w[i]];
      }
      cur[W] = max(notTake, take);
    }
    prev = cur;
  }
  return prev[maxWeight];
}


int knapsackSpace2(int n, vector<int> &w, vector<int> &v, int maxWeight)
{
  vector<int> prev(maxWeight + 1, 0);
  for(int i = w[0]; i <= maxWeight; i++) prev[i] = v[0] * ((int)(i / w[0]));

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
      prev[W] = max(notTake, take);
    }
  }
  return prev[maxWeight];
}

int main(){
    vector<int> weights = {2,4,6};
    vector<int> values = {5,11,13};
    int maxWeight = 10;
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    cout << knapsack(n - 1, weights, values, maxWeight) << endl;
    cout << knapsackDp(weights.size() - 1, weights, values, maxWeight, dp) << endl;
    cout << knapsackTab(n, weights, values, maxWeight) << endl;
    cout << knapsackSpace(n, weights, values, maxWeight) << endl;
    cout << knapsackSpace2(n, weights, values, maxWeight) << endl;
    return 0;
}