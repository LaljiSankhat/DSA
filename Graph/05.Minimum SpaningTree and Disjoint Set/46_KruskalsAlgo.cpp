#include <bits/stdc++.h>
using namespace std;


// it is used to find minimum spanning tree
// sort all the edges
// so here we use disjoint set
// we check if they are not in same component then we attach it and update sum += wt
// if both have same ultimate parent then both in same component so discard that edge


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

int minSpanningTreeKruskalAlgo(int v, vector<vector<int>> adj[]){
    vector<pair<int, pair<int, int>>> edges;

    // O(N + E)
    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            int v = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, v}});
        }
    }

    DisjoinSet ds(v);
    // now sort the edges
    // O(M log M) if m edges
    sort(edges.begin(), edges.end());

    int mstWt = 0;

    // moving all edges with disjoint ds
    // O(M * 2(4 * alpha))
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // if they belong to the same component or not
        if(ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWt;
}
int main(){
    vector<vector<int>> adj[] = {
        {{1, 5}, {2, 1}},
        {{2, 5}}
    };
    int v = 3;

    cout << minSpanningTreeKruskalAlgo(v, adj) << "\n";
    return 0;
}