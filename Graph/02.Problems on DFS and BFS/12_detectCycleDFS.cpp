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
        adj[v].push_back(u);
    }
}

bool detect(int src, int parent, vector<int> adj[], int vis[]){
    vis[src] = 1;

    for(auto adjacentNode : adj[src]){
        if(!vis[adjacentNode]){
            if(detect(adjacentNode, src, adj, vis)){
                return true;
            }
        } else if(adjacentNode != parent){
            return true;
        }
    }

    return false;
}

bool isCycle(vector<int> adj[], int v){

    int vis[v] = {0};

    for(int i = 0; i < v; i++){
        if(!vis[i]) {
            if(detect(i, -1, adj, vis)) return true;
        }
    }

    return false;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    cout << isCycle(adj, n) << endl;

    // TC and SC same as previos
    
    return 0;
}