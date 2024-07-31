#include <bits/stdc++.h>
using namespace std;


/*
    Shortest Distance in a Binary Maze
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance 
between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
If the path is not possible between source cell and destination cell, then return -1.
Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, 
Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. 
The destination cell should be 1.

Example 1:
Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.
*/

// similar leetcode : 1091. Shortest Path in Binary Matrix

// to solve this we consider every element of grid as a node then apply dijkstra algo

int shortestPathInMaze(vector<vector<int>> &grid, pair<int, int> &source, pair<int, int> &destination){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    while(!q.empty()){
        int distOfNode = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x == destination.first && y == destination.second){
            return dist[destination.first][destination.second];
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                int newDist = distOfNode + 1;
                if(newDist < dist[nrow][ncol]){
                    dist[nrow][ncol] = newDist;
                    q.push({newDist, {nrow, ncol}});
                }
            }
        }
    }

    return -1;
}


int main(){
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };
    pair<int, int> src = {0, 1};
    pair<int, int> dest = {2, 2};

    cout << shortestPathInMaze(grid, src, dest) << endl;
    return 0;
}