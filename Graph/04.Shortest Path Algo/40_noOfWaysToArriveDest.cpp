#include <bits/stdc++.h>
using namespace std;


/*
    Number of Ways to Arrive at Destination
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some 
intersections. The inputs are generated such that you can reach any intersection from any other intersection and 
that there is at most one road between any two intersections.
You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a 
road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you 
can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer 
may be large, return it modulo 1e9 + 7.

Example 1:

Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6
*/

// to solve this we have to use another array of ways which will tell by how many ways we can reach that node
// so by this we backtrack the paths
// if we arrive a node by same min distance then we add the ways[parent] into ways[node]

int noOfWaysToReachDestination(int n, vector<vector<int>> &roads){
    vector<pair<int, int>> adj[n];

    for(auto it : roads){
        int u = it[0];
        int v = it[1];
        int d = it[2];

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int mod = (int)(1e9 + 7);

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int distOfNode = it.first;
        int node = it.second;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(distOfNode + wt < dist[adjNode]){
                dist[adjNode] = distOfNode + wt;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            } else if(distOfNode + wt == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}


int main(){
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };
    int n = 7;

    cout << noOfWaysToReachDestination(n, roads) << endl;
    return 0;
}