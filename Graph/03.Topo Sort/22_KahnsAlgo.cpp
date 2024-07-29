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

// it is basically topo sort using BFS
// to solve this we use concept of indegree of node
// we know that if indegree of node is zero then we can go from there to another no one 
// will enter to that node so it is become source node or else no one before that(concept of topo sort)
// first we put all node puts in q which have indegree as zero
// then we apply bfs here we add node to the the ans vector of bfs
// then we traverse all adjacent node
// decrease the indegree of adjacent Node becuase we reach adjacent node by current node 
// now if its indegree become zero then we put it into the queue
// if indegree not become zero then we know that someone node has before that adjacent node other then our current node

vector<int> kahnsAlgo(int v, vector<int> adj[]){
    int indegree[v] = {0};

    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    } 

    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto adjacentNode : adj[node]){
            indegree[adjacentNode]--;
            if(indegree[adjacentNode] == 0){
                q.push(adjacentNode);
            }
        }
    }

    return ans;
}
 
int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    vector<int> ans = kahnsAlgo(n, adj);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    
    return 0;
}