#include <bits/stdc++.h>
using namespace std;


/*
    Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 75K+Points: 4
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where
a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be
distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:
Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:
Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.
*/

// so if island have same shape then it count only once 

// to solve this we use traversal and store shape in set, to store shape we consider first node as base 
// and store all points in list and put it in set
// if two shapes are same then list of that shape will be the same

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &list, int row0, int col0){
    vis[i][j] = 1;
    list.push_back({i - row0, j - col0});
    int n = grid.size();
    int m = grid[0].size();
    

    int drow[] = {-1, 0, 1, 0};        
    int dcol[] = {0, 1, 0, -1}; 

    for(int k = 0; k < 4; k++){
        int nrow = i + drow[k];
        int ncol = j + dcol[k];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, grid, vis, list, row0, col0);
        }
    }
}


int noOfDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vector<pair<int, int>> list;
            if(!vis[i][j] && grid[i][j] == 1){
                dfs(i, j, grid, vis, list, i, j);
                ans.insert(list);
            }
        }
    }

    return ans.size();
}


int main(){
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    
    cout << noOfDistinctIslands(grid) << endl;

    // sc = n * m * log(n * m)(this is for storing in set) for the vis + n * m for recursion
    // tc = n * m for loop and n * m * 4 for dfs calls
    return 0;
}