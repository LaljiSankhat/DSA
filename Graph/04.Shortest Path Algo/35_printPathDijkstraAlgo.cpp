#include <bits/stdc++.h>
using namespace std;


// so we need to print the path of dijkstra algo
// so here we rember from where i come so it is memoization
// to do this we use parent array which will store from where the node is come in path

vector<int> printDijkstraAlgo(int src, int dest, int v, vector<vector<int>> &edges){
    vector<vector<int>> adj[v + 1];
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v + 1, 1e9);
    vector<int> parent(v + 1);
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int node = pq.top().second;
        int distanceOfNode = pq.top().first;
        pq.pop();

        for(auto it : adj[node]){
            int edgeWt = it[1];
            int adjNode = it[0];
            int requiedDist = distanceOfNode + edgeWt;
            if(requiedDist < dist[adjNode]){
                parent[adjNode] = node;
                dist[adjNode] = requiedDist;
                pq.push({requiedDist, adjNode});
            }
        }
    }

    vector<int> path;
    int node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);

    reverse(path.begin(), path.end());

    return path;
}

int main(){
    int v = 5;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 4, 3},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };
    // {i, j, weight}
    int src = 1;
    int dest = 5;

    vector<int> ans = printDijkstraAlgo(src, dest, v, edges);

    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}