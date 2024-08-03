#include <bits/stdc++.h>
using namespace std;


/*
    Connecting the graph
You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add 
that edge between any two vertices in one operation. Find the minimum number of operations that will be 
required to connect the graph.
If it is not possible to connect the graph, return -1.

Example 1: 

Input:
n = 4
m = 3
Edges = [ [0, 1] , [0, 2] , [1, 2] ]
Output:
1
Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
*/

// similar leetCode : 1319. Number of Operations to Make Network Connected


class DisjoinSet{
    vector<int> rank, parent, size;

    public:
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



int operationToMakeConnected(int n, vector<vector<int>> &edges){
    int m = edges.size();

    DisjoinSet ds(n);
    int extraEdges = 0;
    for(auto it : edges){
        if(ds.findUPar(it[0]) == ds.findUPar(it[1])) extraEdges++;
        else ds.unionBySize(it[0], it[1]);
    }

    int noOfProvinces = 0;
    for(int i = 0; i < n; i++){
        if(ds.findUPar(i) == i) noOfProvinces++;
    }

    int edgesRequired = noOfProvinces - 1;

    // int extraEdges = m - (n - 1);

    if(extraEdges >= edgesRequired) return edgesRequired;
    return -1;
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    int n = 3;
    cout << operationToMakeConnected(n, edges) << "\n";
    return 0;
}