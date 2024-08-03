#include <bits/stdc++.h>
using namespace std;


/*
    827. Making A Large Island
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s. 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change 
*/

// so here we have to change onlu one 0 to 1 and return maximum possible island


class DisjoinSet{

    public:
    vector<int> rank, parent, size;
    DisjoinSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else { // rank are same
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    
    // so here we are doing path compression so rank will not tell about height so why not we use size istead of rank

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else { // if it is greater or same in both case we will be attach and increase size 
            // in same case we can attach any to any so no need for extra case
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        
    }
};

bool isValid(int i, int j, int n, int m){
    return i < n && i >= 0 && j < m && j >= 0;
}

int maxConnections(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    DisjoinSet ds(n * m);

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // union where is one
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0) continue;
            int node = i * m + j;
            for(int k = 0; k < 4; k++){
                int adjRow = i + drow[k];
                int adjCol = j + dcol[k];
                int adjNode = m * adjRow + adjCol;
                if(isValid(adjRow, adjCol, n, m) && grid[adjRow][adjCol] == 1){
                    ds.unionBySize(node, adjNode);
                }
            }
        }
    }

    int largeIsland = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == 1) continue;
            set<int> component;
            int node = m * row + col;

            for(int k = 0; k < 4; k++){
                int adjRow = row + drow[k];
                int adjCol = col + dcol[k];
                int adjNode = adjRow * m + adjCol;

                if(isValid(adjRow, adjCol, n, m) && grid[adjRow][adjCol] == 1){
                    int ultimateParent = ds.findUPar(adjNode);
                    component.insert(ultimateParent);
                }
            }

            int tempSize = 1; // 1 for itself
            for(auto it : component){
                tempSize += ds.size[it];
            }

            largeIsland = max(largeIsland, tempSize);
        }
    }

    // now to handle edges cases like all ones and zeros
    for(int cellNo = 0; cellNo < n * m; cellNo++){
        largeIsland = max(largeIsland, ds.size[ds.findUPar(cellNo)]);
    }

    return largeIsland;
}

int main(){
    vector<vector<int>> grid = {{1, 0}, {0, 1}};

    cout << maxConnections(grid);
    return 0;
}