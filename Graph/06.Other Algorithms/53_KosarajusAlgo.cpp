#include <bits/stdc++.h>
using namespace std;


/* 
    Strongly Connected Components (Kosaraju's Algo)
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly 
connected components in the graph.
*/

// Kosaraju's Algorithm 

// it is used to find the strongly connected components(SCC) in graph
// question can be find the total Scc in graph or print 
// SCC - only valid for directed graph

// SCC is component in which can reach any node to any node in that component

// Algorithm
// s - 1 : sort the all the edges according to finish time (bactrack with dfs)
// s - 2 : reverse the graph 
// s - 3 : do a dfs


void dfs(int node, vector<vector<int>> adj, vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}

void dfs3(int node, vector<int> &vis, vector<int> adjT[]){
    vis[node] = 1;

    for(auto it : adjT[node]){
        if(!vis[node]){
            dfs3(it, vis, adjT);
        }
    }
}


int kosarajuAlgorithm(int v, vector<vector<int>> &adj){
    vector<int> vis(v, 0);
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    // now reverse the graph
    vector<int> adjT[v];
    for(int i = 0; i < v; i++){
        vis[i] = 0; // unvisit all the node so we can reuse in futhur dfs
        for(auto it : adj[i]){
            adjT[it].push_back(i);
        }
    }

    // perform dfs on order of finishing time
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!vis[node]){
            scc++;
            dfs3(node, vis, adjT);
        }
    }

    return scc;
}

int main(){
    vector<vector<int>> adj = {
        {1, 0}, {0, 2, 3},
        {2, 1}, 
        {3, 4}
    };
    int v = 5;

    cout << kosarajuAlgorithm(v, adj);
    return 0;
}