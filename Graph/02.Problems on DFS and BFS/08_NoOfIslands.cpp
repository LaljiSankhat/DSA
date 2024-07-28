#include <bits/stdc++.h>
using namespace std;

/*
    Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water)
     and '1's(Land). Find the number of islands.
     Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent 
     lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:
Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Example 2:
Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
 */

void bfsOfNode(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){

    /*
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int g = grid.size();

    while(!q.empty()){
        pair<int, int> p = q.front();
        int m = p.first;
        int n = p.second;
        vis[m][n] = 1;

        // up left
        if(m - 1 >= 0 && n - 1 >= 0 && !vis[m - 1][n - 1]){
            q.push(make_pair(m - 1, n - 1));
        }
        // up
        if(m - 1 >= 0  && !vis[m - 1][n]){
            q.push(make_pair(m - 1, n));
        }
        // up right
        if(m - 1 >= 0 && n + 1 < g && !vis[m - 1][n + 1]){
            q.push(make_pair(m - 1, n + 1));
        }
        // left side
        if(n - 1 >= 0 && !vis[m][n - 1]){
            q.push(make_pair(m, n - 1));
        }
        // right side
        if(n + 1 < g && !vis[m][n + 1]){
            q.push(make_pair(m, n + 1));
        }
        // down left
        if(m + 1 < g && n - 1 >= 0 && !vis[m + 1][n - 1]){
            q.push(make_pair(m + 1, n - 1));
        }
        // down 
        if(m + 1 < g && !vis[m + 1][n]){
            q.push(make_pair(m + 1, n));
        }
        // down right 
        if(m + 1 < g && n + 1 < g && !vis[m + 1][n + 1]){
            q.push(make_pair(m + 1, n + 1));
        }

        q.pop();

    }

    */

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    int m = grid.size();
    int n = grid[0].size();

    // Possible directions in which we can move (8 directions)
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                         {0, -1},           {0, 1}, 
                                         {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (auto dir : directions) {
            int new_i = p.first + dir.first;
            int new_j = p.second + dir.second;
            if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !vis[new_i][new_j] && grid[new_i][new_j] == 1) {
                vis[new_i][new_j] = 1;
                q.push(make_pair(new_i, new_j));
            }
        }
    }

}

int noOfIslands(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int islands = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                bfsOfNode(i, j, grid, vis);
                islands++;
            }
        }
    }

    return islands;

}

int main(){
    int n = 6;
    int m = 6;
    vector<vector<int>> grid = {{0,1}, {1,0}, {1, 1}, {1, 0}};
    cout << noOfIslands(grid);

    // SC = O(N^2) (vis array) + O(N ^ 2) (for the queue)
    // TC = N ^ 2 for the grid loop and N^2 * 8 for the bfs so total will be O(N ^ 2)

    return 0;
}