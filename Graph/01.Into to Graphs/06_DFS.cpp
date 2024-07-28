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

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(int it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }

    return;
}

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    int vis[n + 1] = {0};

    vector<int> ans;
    dfs(0, adj, vis, ans);

    return ans;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);
    
    vector<int> dfs = dfsOfGraph(n, adj);

    for(auto it : dfs){
        cout << it << " ";
    }
    return 0;
}