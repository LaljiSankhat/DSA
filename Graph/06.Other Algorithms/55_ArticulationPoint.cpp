#include <bits/stdc++.h>
using namespace std;


/*
    Articulation Point - I
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the 
vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

*/

// articulation point is the node by removel of that will break graph into multiple components

// in order to find we have two arrays 
// tin : start the time of insertion during dfs
// low : mini of all adjacent node apart from parent and visited nodes

int timer = 0; 

void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    int child = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);

            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }

    if(child > 1 && parent == -1) mark[node] = 1;

}

vector<int> articulationPoint(int v, vector<int> adj[]){
    vector<int> vis(v, 0);
    int tin[v];
    int low[v];
    vector<int> mark(v, 0); // mark which are the articulation points

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }

    vector<int> ans;
    for(int i = 0; i < v; i++){
        if(mark[i] == 1){
            ans.push_back(i);
        }
    }

    if(ans.size() == 0) return {-1};

    return ans;
}


int main(){
    vector<int> adj[] = {
        {1},{0, 4}, {3, 4}, {2, 4}, {1, 2, 3}
    };
    int v = 5;

    vector<int> ans = articulationPoint(v, adj);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}