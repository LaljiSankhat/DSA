#include <bits/stdc++.h>
using namespace std;


// Dijkstra give TLE if -ve edge wieght is given 
// to solve this bellman ford algorithm comes into the picture
// it is only applicable for the Undirected graph

// in algorithm
// we relax all the edges n - 1 times sequentially
// in each iteration we relax the edge by using dist[node] + wt < dist[adjNode]

// why N - 1?
// so first you have dist of src only 
// then you do first itersation by this u will get the dist of node which will using src node
// so you get second number
// now iteration by iteration we get the values so need to run loop maximum n - 1 times so we get all values in worst case
// we can furthur run loop but it will not useful

// how to find negetive cycle in loop?
// if we do iteration greater than n - 1 then if value reduced then there is a negative cycle

vector<int> bellmanFordAlgorithm(int v, vector<vector<int>> &edges, int s){
    vector<int> dist(v, 1e8);
    dist[s] = 0;

    for(int i = 0; i < v -1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int edgeW = it[2];

            if(dist[u] != 1e8 && dist[u] + edgeW < dist[v]){
                dist[v] = dist[u] + edgeW;
            }
        }
    }

    

    // Nth relaxation for checking negative cycle
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int edgeW = it[2];

        if(dist[u] != 1e8 && dist[u] + edgeW < dist[v]){
            return {-1};
        }
    }

    return dist;
}


int main(){
    vector<vector<int>> edges = {
        {0, 1, 5},
        {1, 0, 3},
        {1, 2, -1},
        {2, 0, 1}
    };
    int s = 2;
    int v = 3;

    vector<int> ans = bellmanFordAlgorithm(v, edges, s);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    // TC = O(V * E)
    return 0;
}