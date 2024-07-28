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

bool dfs(int node, vector<int> graph[], vector<int> &color){

    for(auto adjacentNode : graph[node]){
        if(color[adjacentNode] == -1){
            color[adjacentNode] = 1 - color[node];
            if(dfs(adjacentNode, graph, color) == false){
                return false;
            }
        } else if(color[adjacentNode] == color[node]){
            return false;
        }
    }

    return true;
}


bool isBipartite(int v, vector<int> graph[]){
    vector<int> color(v, -1);

    for(int i = 0; i < v; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(dfs(i, graph, color) == false) return false;
        }
    }

    return true;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n];
    generateGraph(n, m , adj);
    
    cout << isBipartite(n, adj) << endl;
    return 0;
}