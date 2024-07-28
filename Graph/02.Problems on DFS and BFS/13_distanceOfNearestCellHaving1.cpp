#include <bits/stdc++.h>
using namespace std;


/*
    Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column 
number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
There should be atleast one 1 in the grid.

Example 1:
Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

Example 2:
Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.

*/

// similar question leetcode 542. 01 matrix

/*
    to solve this we use BFS, starts from all 1 putted in queue,
    now if we get 0 then for that 0 distance is 1 and so on...
*/

vector<vector<int>> distanceOfNearestCellHaving1(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, -1));

    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1) {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        ans[row][col] = steps;

        int drow[] = {-1, 0, 1, 0};        
        int dcol[] = {0, 1, 0, -1};    

        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }    
    }

    return ans;
}

int main(){
    vector<vector<int>> mat = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    vector<vector<int>> result = distanceOfNearestCellHaving1(mat);

    for(const auto &row : result) {
        for(const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // TC = O(N * M * 4) (for every node in mat 4 cases are running) 
    // sc = O(N * M) (of arrays and queue nearly n * m)
    return 0;
}