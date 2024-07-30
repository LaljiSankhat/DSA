#include <bits/stdc++.h>
using namespace std;

// dijkstra algo with using Set

vector<int> dijkstraAlgo(int src, int v, vector<vector<int>> adj[]){
    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);

    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto list : adj[node]){
            int adjNode = list[0];
            int wt = list[1];
            int newDist = dist[node] + wt;

            if(newDist < dist[adjNode]){
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = newDist;
                st.insert({newDist, adjNode});
            }

        }
    }

    return dist;
}

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
    return 0;
}