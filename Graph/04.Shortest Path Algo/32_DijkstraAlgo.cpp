#include <bits/stdc++.h>
using namespace std;


/*
    Dijkstra Algorithm
Difficulty: MediumAccuracy: 50.83%Submissions: 167K+Points: 4
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] 
is a list of lists containing two integers where the first integer of each list j denotes there is edge 
between i and j , second integers corresponds to the weight of that  edge . You are given the source 
vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. 
You have to return a list of integers denoting shortest distance between each node and Source vertex S.

Note: The Graph doesn't contain any negative weight cycle. 

Example 1:
Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  
which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S 
returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. 
Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an 
edge between i and j and the second integer w denotes that the weight between edge i and j is w.

Expected Time Complexity: O(V^2).
Expected Auxiliary Space: O(V^2).
*/

// dijkstra algo can be solved using Priority queue or can be Set

// to solve here we use pririty queue method
// so here we have a distance array, min-Heap


vector<int> dijkstraAlgo(int src, int v, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);

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
                dist[adjNode] = requiedDist;
                pq.push({requiedDist, adjNode});
            }
        }
    }

    return dist;
}

// dijkstra doesn't work for the -ve edge weights 
// by -ve edge wt you will go in infinite loop 


int main(){
    int v = 6;
    vector<vector<int>> adj[v] = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 2}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{2, 6}, {3, 2}, {4, 3}}
    };

    vector<int> ans = dijkstraAlgo(0, v, adj);

    for(auto it : ans){
        cout << it << " ";
    }

    // TC = O(E * log(V))

    return 0;
}