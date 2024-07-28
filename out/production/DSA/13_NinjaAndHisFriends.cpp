#include <bits/stdc++.h>
using namespace std;

/*
  Problem statement
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates.
Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place
 i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them.
 When anyone passes from any cell, he will pick all chocolates in it, and then the number
 of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.
If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1).
They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Example:
Input: ‘R’ = 3, ‘C’ = 4
       ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1)
 and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3)
and will colllect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21.
there is no other possible way to collect a greater number of chocolates than 21.
*/

int maxChocolates(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return matrix[i][j1];
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    // Exploring all the paths
    int ans = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        int maxi = -1e8;
        for (int dj2 = -2; dj2 <= 1; dj2++)
        {
            int add = 0;
            if (j1 != j2)
                add = matrix[i][j1] + matrix[i][j2];
            else
                add = matrix[i][j1];
            int res = add + maxChocolates(i + 1, j1 + dj1, j2 + dj2, n, m, matrix);
            maxi = max(maxi, res);
        }
        ans = max(ans, maxi);
    }
    return ans;
}

// Memoization
int maxChocolatesDp(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return matrix[i][j1];
        else
            return matrix[i][j1] + matrix[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // Exploring all the paths
    int ans = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        int maxi = -1e8;
        for (int dj2 = -2; dj2 <= 1; dj2++)
        {
            int add = 0;
            if (j1 != j2)
                add = matrix[i][j1] + matrix[i][j2];
            else
                add = matrix[i][j1];
            int res = add + maxChocolatesDp(i + 1, j1 + dj1, j2 + dj2, n, m, matrix, dp);
            maxi = max(maxi, res);
        }
        ans = max(ans, maxi);
    }
    return dp[i][j1][j2] = ans;
}

// Tabulation
int maxChocolatesTab(int n, int m, vector<vector<int>> &matrix, vector<vector<vector<int>>> &dp)
{
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = matrix[n - 1][j2];
            else
                dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    int maxi = -1e8;
                    for (int dj2 = -2; dj2 <= 1; dj2++)
                    {
                        int add = 0;
                        if (j1 != j2)
                            add = matrix[i][j1] + matrix[i][j2];
                        else
                            add = matrix[i][j1];
                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            add +=  dp[i + 1][j1 + dj1][j2 + dj2];
                        else 
                            add += -1e8;
                        maxi = max(maxi, add);
                    }
                    ans = max(ans, maxi);
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    return dp[0][0][m - 1];
}

// space optimization
int maxChocolatesSpaceOptimized(int n, int m, vector<vector<int>> &matrix){
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

     for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = matrix[n - 1][j2];
            else
                front[j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int ans = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    int maxi = -1e8;
                    for (int dj2 = -2; dj2 <= 1; dj2++)
                    {
                        int add = 0;
                        if (j1 != j2)
                            add = matrix[i][j1] + matrix[i][j2];
                        else
                            add = matrix[i][j1];
                        if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            add +=  front[j1 + dj1][j2 + dj2];
                        else 
                            add += -1e8;
                        maxi = max(maxi, add);
                    }
                    ans = max(ans, maxi);
                }
                cur[j1][j2] = ans;
            }
        }
        front = cur;
    }
    return front[0][m - 1];

}

int main()
{
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << maxChocolates(0, 0, m - 1, n, m, matrix) << endl;
    cout << maxChocolatesDp(0, 0, m - 1, n, m, matrix, dp) << endl;
    cout << maxChocolatesTab(n,m,matrix,dp) << endl;
    cout << maxChocolatesSpaceOptimized(n,m,matrix) << endl;
    return 0;
}