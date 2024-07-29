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

// previosoly we have solve this usinf dfs traversl here we use BFS traversal 
// to solve this first we reverse all the edges and apply topo sort
// we reverse becuase topo sort focus on inderee while safe nodes focus on outdegree
// if out degree is zero then it is terminal node and safe node

vector<int> eventualSafeStates(int v, vector<int> adj[]){
    vector<int> adjRev[v];
    int indegree[v] = {0};

    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i); // reversing the direction of edge
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < v; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto adjacentNode : adjRev[node]){
            indegree[adjacentNode]--;
            if(indegree[adjacentNode] == 0){
                q.push(adjacentNode);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
  
int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n];
    generateGraph(n, m , adj);

    vector<int> ans = eventualSafeStates(n, adj);

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}