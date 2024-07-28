#include <bits/stdc++.h>
using namespace std;


// Provinces : no of suggraphs of graph which are not connected to each other


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

vector<int> bfsOfGraph(int v, vector<int> adj[], int vis[]){
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

int numberOfProvinces(int v, vector<int> adj[]){
    // int v = adj.size();
    int vis[v] = {0};
    int provinces = 0;

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            bfsOfGraph(v, adj, vis);
            provinces++;
        }        
    }

    return provinces;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);
    cout << numberOfProvinces(n, adj);
    // SC = O(n) (for visited array) + O(n) (for the queue in worst case)
    // TC = O(n) (for the i to v loop) + O(V + 2E) (for the dfs)
    
    return 0;
}
