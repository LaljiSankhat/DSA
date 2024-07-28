#include <bits/stdc++.h>
using namespace std;


/*
    Eventual Safe States
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible 
path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


*/

// safe nodes are the nodes which are not going in the cycle of graph via any path and also it ends at terminal node
// which have outdegree 0

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

bool dfs(int node, vector<int> adj[], int vis[], int pathVisited[], int check[]){
    vis[node] = 1;
    pathVisited[node] = 1;
    check[node] = 0;

    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode]){
            vis[adjacentNode] = 1;
            if(dfs(adjacentNode, adj, vis, pathVisited, check)) {
                check[node] = 0;
                return true;
            }
        } else if(pathVisited[adjacentNode]){
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVisited[node] = 0;

    return false;
}

vector<int> safeNodes(int v, vector<int> adj[]){
    int vis[v] = {0};
    int pathVisited[v] = {0};
    vector<int> safeNodes;
    int check[v] = {0};
    
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, adj, vis, pathVisited, check);
        }
    }

    for(int i = 0; i < v; i++){
        if(check[i] == 1){
            safeNodes.push_back(i);
        }
    }

    return safeNodes;
}

int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n];
    generateGraph(n, m , adj);

    vector<int> ans = safeNodes(n, adj);

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " " << endl;
    }
    return 0;
}