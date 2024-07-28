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

bool check(int start, int v, vector<int> adj[],int color[]){
    color[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adjacentNode : adj[node]){
            if(color[adjacentNode] == -1){
                color[adjacentNode] = 1 - color[node]; // store it coplement color
                q.push(adjacentNode);
            } 
            else if(color[node] == color[adjacentNode]) return false;
        }
    }

    return true;
}

bool isBipartite(int v, vector<int> adj[]){
    int color[v] = {-1};
    for(int i = 0; i < v; i++){
        if(color[i] == -1){
            if(check(i, v, adj, color) == false) return false;
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
    // int a = 1;
    // cout << !a << endl;

    // tc = V + 2E + V(of loop)

    // sc = V for color + V for queue
    return 0;
}