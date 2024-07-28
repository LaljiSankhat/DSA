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
    }
}

// works only for the Directed Acyclic Graph

void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
    vis[node] = 1;

    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            dfs(adjacentNode, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int v, vector<int> adj[]){
    int vis[v] = {0};
    stack<int> st;

    for(int i = 0; i < v; i++){
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    vector<int> ans = topoSort(n, adj);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}