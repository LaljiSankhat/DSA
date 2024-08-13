#include <bits/stdc++.h>
using namespace std;


/*
    778. Swim in Rising Water
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to 
another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. 
You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
*/

int pathWithMinEffort(vector<vector<int>> &heights){
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> effort(n, vector<int>(m, 1e9));
    effort[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}});

    while(!pq.empty()){
        auto it = pq.top();
        int dif = it.first;
        int x = it.second.first;
        int y = it.second.second;
        pq.pop();

        if(x == n - 1 && y == m - 1) return effort[n - 1][m - 1];
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                int newDiff = abs(heights[nrow][ncol]);
                int effortOfAdj = max(dif, newDiff);
                if(effortOfAdj < effort[nrow][ncol]){
                    effort[nrow][ncol] = effortOfAdj;
                    pq.push({effortOfAdj, {nrow, ncol}});
                }
            }
        }
    }

    return -1;
}

int swimInWater(vector<vector<int>> &grid){
    return pathWithMinEffort(grid);
    
}


int main(){
    vector<vector<int>> grid = {{0,1,2,3,4}, {24,23,22,21,5}, {12,13,14,15,16}, {11,17,18,19,20}, {10,9,8,7,6}};
    cout << swimInWater(grid);
    return 0;
}