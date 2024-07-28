#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[]){
    int vis[v] ={0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();   
        q.pop();  
        bfs.push_back(node);   

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void generateGraph(int n, int m, vector<int> adj[]){
    // Predefined edges for the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {1, 3},
        {2, 3},
        {2, 4},
        {3, 4},
        {4, 5}
    };
    // Populate adjacency list
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
 

int main(){
    int n = 6;
    int m = 6;
    // Initialize adjacency list
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    

    vector<int> bfs = bfsOfGraph(n, adj);
    for(auto it : bfs){
        cout << it << " ";
    }
    return 0;
}