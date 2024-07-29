#include <bits/stdc++.h>
using namespace std;


/*
    Shortest path in Directed Acyclic Graph
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of 
length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, 
then return -1 for that vertex.

Example1:
Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.

Example2:
Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer 
N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the 
input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
Expected Space Complexity: O(N)
*/

// here graph is with distances or wieghts
// we have to find the shortest path of any node from src node

// to solve this first do topo sort using dfs by which we know from that where we can reach
// now take the nodes out of the stack and relax the edges
// for relaxation make a distance array with all infinity
// mark 0 for src node



void generateGraph(int n, int m, vector<pair<int, int>> adj[]){
    vector<pair<pair<int, int>, int>> edges = {
        {{0, 1}, 1},
        {{1, 2}, 1},
        {{2, 3}, 1},
        {{1, 3}, 1},
        {{3, 4}, 1},
        {{2, 4}, 1},
        {{4, 5}, 1}
    };
    for (const auto& edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int d = edge.second;
        adj[u].push_back({v, d});
        // adj[v].push_back(u);
    }
}

void dfs(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
    vis[node] = 1;

    for(auto adjacentNode : adj[node]){
        if(!vis[adjacentNode.first]){
            dfs(adjacentNode.first, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int n, vector<pair<int, int>> adj[]){
    // topo sort
    int vis[n] = {0};
    stack<int> st;

    // O(N + E)
    for(int i = 0; i < n; i++){
        if(!vis[i]) dfs(i, adj, vis, st);
    }

    // do the distance things
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // O(N + M)
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    return dist;
}

int main(){
    int n = 6;
    int m = 6;
    vector<pair<int, int>> adj[n];
    generateGraph(n, m , adj);

    vector<int> ans = shortestPath(n, adj);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}