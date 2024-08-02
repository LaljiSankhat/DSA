#include <bits/stdc++.h>
using namespace std;

// if we want to find the two node are in same component or not 
// by dfs or bfs is done by v + 2e but by disjoint set it can be done in constant time
// this ds is used in Dynamic Graph

// Dynamic graph is graph under formation process stoped and generated

// it gives two functionality 1. find the parent 2. Union (can be done in two ways 1. Rank 2. Size)

// Union by Rank method
// first we need rank and a parent array
// union(u, v)
// first find ultimate parent of u and v termed as pu and pv
// find rank of pu and pv
// connect smaller rank to larger rank always (in equality connect anyone to anyone)
// tc of union is 4 * alpha which is proven 
// 4 * alpha nearly equals to the constant


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


int main(){
    DisjoinSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);

    // does 3 and 7 belong to same component
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same parent  \n";
    } else {
        cout << "Not same \n";
    }
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout << "Same parent  \n";
    } else {
        cout << "Not same \n";
    }

    // tc = 4 * alpha = constant
    return 0;
}