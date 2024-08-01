#include <bits/stdc++.h>
using namespace std;


/*
    Path With Minimum Effort
You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move 
up, down, left, or right, and you wish to find the route with minimum effort.
Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Example 1:
Input:
row = 3
columns = 3 
heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 
2
Explaination: 
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.

Example 2:
Input:
row = 2
columns = 2 
heights = [[7,7],[7,7]]
Output: 
0
Explaination: 
Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.
*/

// similar leetcode : 1631. Path With Minimum Effort

// effort is the maximum absolute diff of two consecutive cells 
// we have to find path with this min efforts

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
                int newDiff = abs(heights[nrow][ncol] - heights[x][y]);
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


int main(){
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    int n = heights.size();
    int m = heights[0].size();

    cout << pathWithMinEffort(heights) << endl;

    // tc = E log V
    // so for the grid we have n * m cell (nodes) for evry we have 4 direction
    // so E = N * M * 4
    // TC = O(n * m * 4 log(n * m))
    return 0;
}