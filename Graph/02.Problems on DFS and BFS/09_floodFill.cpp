#include <bits/stdc++.h>
using namespace std;

/*
    733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from 
the pixel image[sr][sc].To perform a flood fill, consider the starting pixel, plus any pixels connected
4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 
4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the 
aforementioned pixels with color.Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) 
(i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel 
(i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

void dfs(int i, int j, vector<vector<int>> &grid, int color, int initialColor){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;

    if(grid[i][j] == initialColor){
        grid[i][j] = color;
        dfs(i - 1, j, grid, color, initialColor);
        dfs(i + 1, j, grid, color, initialColor);
        dfs(i, j - 1, grid, color, initialColor);
        dfs(i, j + 1, grid, color, initialColor);
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> grid = image;

    int initialColor = grid[sr][sc];

    dfs(sr, sc, grid, color, initialColor);

    return grid;
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> grid = floodFill(image, sr, sc, color);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << "" << endl;
    }

    // TC = O(N * M * 4) (for every node we call for four neighbour in worst case)  it is nearly O(N * M)
    // SC = O(N * M) (for the extra 2d array to store the answer) + O(N * M) (recursive stack space)
    return 0;
}