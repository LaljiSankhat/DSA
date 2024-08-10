#include <bits/stdc++.h>
using namespace std;


/*
    959. Regions Cut By Slashes
2136
Medium
Topics
Companies
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:


Input: grid = [" /","/ "]
Output: 2
Example 2:


Input: grid = [" /","  "]
Output: 1
Example 3:


Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &binaryMatrix){
    vis[i][j] = 1;
    int n = binaryMatrix.size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        int nrow = i + drow[k];
        int ncol = j + dcol[k];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && binaryMatrix[nrow][ncol] == 1 && !vis[nrow][ncol]){
            dfs(nrow, ncol, vis, binaryMatrix);
        }
    }
}

int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int size = 3 * n;

    vector<vector<int>> binaryMatrix(size, vector<int>(size, 1));

    // generating binary matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '/'){
                binaryMatrix[3 * i][3 * j + 2] = 0;
                binaryMatrix[3 * i + 1][3 * j + 1] = 0;
                binaryMatrix[3 * i + 2][3 * j] = 0;
            } else if(grid[i][j] == '\\'){
                binaryMatrix[3 * i][3 * j] = 0;
                binaryMatrix[3 * i + 1][3 * j + 1] = 0;
                binaryMatrix[3 * i + 2][3 * j + 2] = 0;
            }
        }
    }

    // for(int i = 0; i < size; i++){
    //     for(int j = 0; j < size; j++){
    //         cout << binaryMatrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // to find the isolated region we apply simple dfs to the binary matrix 
    // where if there is 1 then it is a node of graph
    vector<vector<int>> vis(size, vector<int>(size, 0));

    int cnt = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(binaryMatrix[i][j] == 1 && !vis[i][j]){
                dfs(i, j, vis, binaryMatrix);
                cnt++;
            }
        }
    }

    return cnt;

}


int main(){
    vector<string> grid = {"//", "/ "};
    // string s = "\\ \\ \\";
    // cout << s.size();
    // for(int i = 0; i < s.size(); i++){
    //     cout << s[i];
    // }
    cout << regionsBySlashes(grid);
    return 0;
}