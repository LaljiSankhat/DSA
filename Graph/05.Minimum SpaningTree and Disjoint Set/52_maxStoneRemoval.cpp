#include <bits/stdc++.h>
using namespace std;


/*
    947. Most Stones Removed with Same Row or Column
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the 
largest possible number of stones that can be removed. 

Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
*/

// you can remove the stone if it shares row or col with the other stone

// to solve this connect the stones which shares the same row or col 
// so it will become a component of graph 
// in a component we can remove all the nodes except 1 node
// so our answer will be no of nodes - noOfComponents

// so here we will be storing row and cols as nodes in the graph
// row no will be 0 to row - 1, and col no = col + noOfRow


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


int maxStoneRemoved(vector<vector<int>> &stones, int n){
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjoinSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNode;

    // combining rows and cols
    for(auto it : stones){
        int nodeRow = it[0];
        int nodeCol = maxRow + it[1] + 1;

        ds.unionBySize(nodeRow, nodeCol);
        stoneNode[nodeRow] = 1;
        stoneNode[nodeCol] = 1;
    }

    // count the connected components
    int cnt = 0;
    for(auto it : stoneNode){
        if(ds.findUPar(it.first) == it.first) cnt++;
    }

    return n - cnt; // noOfStones - connectedComponents
}


int main(){
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int n = 6;

    cout << maxStoneRemoved(stones, n);
    return 0;
}