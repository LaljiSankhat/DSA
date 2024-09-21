#include <bits/stdc++.h>
using namespace std;


/*
    1937. Maximum Number of Points with Cost
2106
Medium
Topics
Companies
Hint
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
 

Constraints:

m == points.length
n == points[r].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= points[r][c] <= 105
*/

long long f(int i, int j, vector<vector<int>>& points){
    if(i == 0) return points[i][j];

    long long maxi = INT_MIN;
    for(int k = 0; k < points[0].size(); k++){
        long long temp = f(i - 1, k, points) + (long long)points[i][j];
        // remove the cost to reach there
        temp -= abs(j - k);
        maxi = max(maxi, temp);
    }

    return maxi;
}

long long fDp(int i, int j, vector<vector<int>>& points, vector<vector<int>> &dp){
    if(i == 0) return points[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    long long maxi = INT_MIN;
    for(int k = 0; k < points[0].size(); k++){
        long long temp = f(i - 1, k, points) + (long long)points[i][j];
        // remove the cost to reach there
        temp -= abs(j - k);
        maxi = max(maxi, temp);
    }

    return dp[i][j] = maxi;
}

long long fTab(vector<vector<int>>& points){
    int n = points.size();
    int m = points[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));

    for(int k = 0; k < m; k++){
        dp[0][k] = points[0][k];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            long long maxi = INT_MIN;
            for(int k = 0; k < points[0].size(); k++){
                long long temp = dp[i - 1][k] + (long long)points[i][j];
                // remove the cost to reach there
                temp -= abs(j - k);
                maxi = max(maxi, temp);
            }
            dp[i][j] = maxi;
        }
    }

    long long ans = INT_MIN;
    for(int k = 0; k < points[0].size(); k++){
        ans = max(ans, (long long)dp[n - 1][k]);
    }

    return ans;
}

long long fSpace(vector<vector<int>>& points){
    int n = points.size();
    int m = points[0].size();
    vector<long long> prev(m, 0);

    for(int k  = 0; k < m; k++){
        prev[k] = points[0][k];
    }

    for(int i = 1; i < n; i++){
        vector<long long> cur(m, 0);
        for(int j = 0; j < m; j++){
            long long maxi = INT_MIN;
            for(int k = 0; k < points[0].size(); k++){
                long long temp = prev[k] + (long long)points[i][j];
                // remove the cost to reach there
                temp -= abs(j - k);
                maxi = max(maxi, temp);
            }
            cur[j] = maxi;
        }
        prev = cur;
    }

    long long ans = INT_MIN;
    for(int k = 0; k < points[0].size(); k++){
        ans = max(ans, (long long)prev[k]);
    }

    return ans;
}

long long maxPoints(vector<vector<int>>& points) {
    int n = points.size(); 
    int m = points[0].size();
    long long ans = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for(int i = 0; i < m; i++){
        // ans = max(ans, f(n - 1, i, points));
        ans = max(ans, fDp(n - 1, i, points, dp));
    }

    return ans;
}

// this is simple dp solution which will take n * m * m so we have to optimise it


// to do this we use something like double dp technique
// in this we have two rows like left and right
// left will tell what is max value we can get by choosing from left of prev row 
// right will tell what is max value we can get by choosing from the right of prev row from that cell
// so we have to check only two values one is left second is right and third is prev of that 

// so to pick the values we have to check which is max for that cell in left and right

long long maximumPoints(vector<vector<int>>& points){
    int n = points.size();
    int m = points[0].size();

    long long ans = INT_MIN;

    vector<long long> prevRow(points[0].begin(), points[0].end());
    for(int r = 1; r < n; r++){
        vector<long long> nextRow(points[r].begin(), points[r].end());
        vector<long long> left(m, 0), right(m, 0);

        left[0] = prevRow[0];
        for(int col = 1; col < m; col++){
            left[col] = max(prevRow[col], left[col - 1] - 1);
        }

        right[m - 1] = prevRow[m - 1];
        for(int col = m - 2; col >= 0; col--){
            right[col] = max(prevRow[col], right[col + 1] - 1);
        }

        for(int i = 0; i < m; i++){
            nextRow[i] += max(left[i], right[i]);
        }

        prevRow = nextRow;
    }

    // long long ans = 0;
    for(int i = 0; i < m; i++){
        ans = max(ans, prevRow[i]);
    }

    return ans;
}


int main(){
    vector<vector<int>> grid = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    
    cout << maxPoints(grid);
    cout << fTab(grid);
    cout << fSpace(grid);
    cout << maximumPoints(grid);
    return 0;
}