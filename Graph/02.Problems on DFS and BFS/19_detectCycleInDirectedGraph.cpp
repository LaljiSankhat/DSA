#include <bits/stdc++.h>
using namespace std;

void generateGraph(int n, int m, vector<int> adj[]){
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {1, 3},
        {3, 4},
        {2, 4},
        {4, 5}
    };
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        // adj[v].push_back(u);  removed because of directed graph
    }
}


// to  check cycle in directed graph we have to use a pathvisited array which will tell you are path visited or not
// so a node occure second time in traversal we know if it is in the path then it will cycle if it is not in 
// path then it is not a cycle, becuse we arrive same node with different path so not a cycle   

bool dfs(int node, vector<int> adj[], int vis[], int pathVisited[]){
    vis[node] = 1;
    pathVisited[node] = 1;

    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            vis[adjacentNode] = 1;
            if(dfs(adjacentNode, adj, vis, pathVisited)) return true;
        } else if(pathVisited[adjacentNode]){
            return true;
        }
    }

    pathVisited[node] = 0;

    return false;
}

bool isCycle(int v, vector<int> adj[]){
    int vis[v] = {0};
    int pathVisited[v] = {0};

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathVisited)) return true;
        }
    }

    return false;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n];
    generateGraph(n, m , adj);

    cout << isCycle(n, adj) << endl;    
    return 0;
}