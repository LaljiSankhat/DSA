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

// here we have to find the shortes path in the undirected graph
// we are given undirected graph with unit weights edges
// first we define dist array as infinity
// then apply BFS 
// in queue we will store the node and dist of node from source 
// by traversing all adjacent node if find small distance to reach adjacent node then prev then we update it
// also put that node with new small distance

vector<int> shortestPathInUndirectedGraph(int src, int v, vector<int> adj[]){
    // int dist[v] = {0};
    vector<int> dist(v, INT_MAX);
    queue<pair<int, int>> q;

    q.push({src, 0});
    dist[src] = 0;

    while(!q.empty()){
        int node = q.front().first;
        int distOfNode = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]){
            int requiredDist = distOfNode + 1;
            if(requiredDist < dist[adjacentNode]){
                dist[adjacentNode] = requiredDist;
                q.push({adjacentNode, requiredDist});
            }
        }
    }

    return dist;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    vector<int> ans = shortestPathInUndirectedGraph(0, n, adj);

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}