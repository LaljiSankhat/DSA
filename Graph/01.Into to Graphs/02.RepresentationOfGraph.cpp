#include <bits/stdc++.h>
using namespace std;

// we are given with n and m where n are number of nodes and m are the no, of edges

int main(){
    int n, m;
    cin >> n >> m;

    // matrix representation
    int adj[n + 1][m + 1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // list representation
    vector<int> adj2[n + 1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    return 0;
}