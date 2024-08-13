#include <bits/stdc++.h>
using namespace std;


/*
    1568. Minimum Number of Days to Disconnect Island

You are given an m x n binary grid grid where 1 represents land and 0 represents water. 
An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

Example 1:
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Example 2:
Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 30
grid[i][j] is either 0 or 1.
*/

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
    vis[i][j] = 1;
    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        int nrow = i + drow[k];
        int ncol = j + dcol[k];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, grid);
        }
    }
}

int noOfComponents(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                dfs(i, j, vis, grid);
                cnt++;
            }
        }
    }

    return cnt;
}

int minDaysToDisconnectIsland(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    // first find the componenets if componenet 0 or greater than 1 then return 0 days
    if(noOfComponents(grid) == 0 || noOfComponents(grid) > 1) return 0;

    // now removing one by one components if its creater multiple component then it requires one day
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                grid[i][j] = 0;
                int components = noOfComponents(grid);
                if(components == 0 || components > 1) return 1;
                grid[i][j] = 1;
            }
        }
    }

    return 2;
}


int main(){
    vector<vector<int>> grid = {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}};
    cout << minDaysToDisconnectIsland(grid);
    return 0;
}