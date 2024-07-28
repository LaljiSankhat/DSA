#include <bits/stdc++.h>
using namespace std;


/*
    Number Of Enclaves
Difficulty: MediumAccuracy: 50.93%Submissions: 72K+Points: 4
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking 
off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.

Example 2:
Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
*/

// similar leetcode problem 1020. Number of Enclaves

void dfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<int>> &vis){

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int drow[] = {-1, 0, 1, 0};        
        int dcol[] = {0, 1, 0, -1}; 

        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 1;
                grid[nrow][ncol] = 0;
                q.push({nrow,ncol});
            }
        }
    }
}


int noOfEnclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++){
        // first row 
        if(grid[0][i] == 1){
            q.push({0, i});
            vis[0][i] == 1;
            grid[0][i] = 0;
        }

        // last row
        if(grid[n - 1][i] == 1){
            q.push({n - 1, i});
            vis[n - 1][i] == 1;
            grid[n - 1][i] = 0;
        }
    }

    for(int j = 0; j < n; j++){
        // first row 
        if(grid[j][0] == 1){
            q.push({j, 0});
            vis[j][0] == 1;
            grid[j][0] = 0;
        }

        // last row
        if(grid[j][m - 1] == 1){
            q.push({j, m - 1});
            vis[j][m - 1] == 1;
            grid[j][m - 1] = 0;
        }
    }

    dfs(grid, q, vis);

    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                count++;
            }
        }
    }
    
    return count;
}

int main(){
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};

    cout << noOfEnclaves(grid) << endl;

    // it same as previos quetion so time and space complexity will be same
    return 0;
}