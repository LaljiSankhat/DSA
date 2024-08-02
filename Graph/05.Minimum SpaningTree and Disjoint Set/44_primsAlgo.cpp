#include <bits/stdc++.h>
using namespace std;

// we have to find the minimmum spanning tree and return the sum of its edges

// to find that we have to follow the steps
// first we require a priority queue which will store the {wt, node, parent}
// another we need is visited array
// sum = 0 which will count the edge weight of MST
// and MST list which will store the edges of graph which will part of MST
// first we put {0, 0, -1} in pq becuse there is node 0 wt-0 with no parent so 

// we took out from pq then mark node as vis
// then we add its wt to sum 
// then add all its adjacent node with weight in pq


// in this question no need to return mst but if ask then store edge in mst while took out from queue


int minimumSpaningTree(int v, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(v, 0);

    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edW = it[1];

            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }


    return sum;
    
}

int main(){
    vector<vector<int>> adj[] = {
        {{1, 5}, {2, 1}},
        {{2, 5}}
    };
    int v = 3;

    cout << minimumSpaningTree(v, adj) << endl;

    // for TC 
    // while loop is runnig for the no of Edges timme so E
    // for every E we do work of heap so log (heap size) so atmax heap size is E
    // for adjNodes we have E * log E
    // TC = O(E * log E + E log E)
    // tc = O(E log E)
    return 0;
}