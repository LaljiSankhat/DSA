#include <bits/stdc++.h>
using namespace std;


/*
    787. Cheapest Flights Within K Stops
There are n cities connected by some number of flights. You are given an array flights where 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1. 

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

// so here we have to give pririty to the stops greater than the distance, so we will be using normal queue
// so q will be {stops, node, dist}


int cheapestFlightWithinKStops(int n, vector<vector<int>>& flights, int src, int dst, int k){
    vector<pair<int, int>> adj[n];

    for(auto it : flights){
        int u = it[0];
        int v = it[1];
        int cost = it[2];
        adj[u].push_back({v, cost});
    }

    queue<pair<int, pair<int, int>>> q;  // {stops, node, dist}
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k) continue;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(cost + wt < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + wt;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }

    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}

int main(){
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };
    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;

    cout << cheapestFlightWithinKStops(n, flights, src, dst, k) << endl;

    // TC = E log V 
    // but here dont use priority queue
    // so TC = E = flight.size()
    return 0;
}