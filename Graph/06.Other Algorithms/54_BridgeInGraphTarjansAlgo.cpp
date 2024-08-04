#include <bits/stdc++.h>
using namespace std;


/*
    1192. Critical Connections in a Network
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a 
network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can 
reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order. 

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

// to solve this we use a time array and a lowestTime array
// lowestTime : minimum lowest time insertion of all adjacent nods apart parent


int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges){
    vis[node] = 1;

    tin[node] = low[node] = timer;
    timer++;

    for(auto it : adj[node]){
        if(it == parent) continue;
        if(vis[it] == 0){
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            // node ---- it     is a bridge
            // if it lowest is not reachabe to tin of node then there is bridge
            if(low[it] > tin[node]) { 
                bridges.push_back({node, it});
            }
        } else {
            low[node] = min(low[node], low[it]);
        }
    }
}


vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    int tin[n]; // time of insertion
    int low[n]; // lowest time 

    vector<vector<int>> bridges; // to store bridges

    dfs(0, -1, vis, adj, tin, low, bridges);

    return bridges;

}


int main(){
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };

    vector<vector<int>> ans = criticalConnections(n, connections);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    // tc = V + 2E (simple dfs)
    // sc = V + 2E (graph) + 3 N (for tin, vis, low)
    return 0;
}