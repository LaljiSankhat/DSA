#include <bits/stdc++.h>
using namespace std;


// leet code 2467 : Most Profitable Path in a Tree


void bobPath(int node, vector<int> adj[], vector<int> &bobVis, vector<int> &path, vector<int> &ans){
    if(node == 0) {
        // path.push_back(0);
        ans = path;
        return;
    }
    bobVis[node] = 1;
    for(int adjNode : adj[node]){
        if(!bobVis[adjNode]){
            path.push_back(adjNode);
            bobPath(adjNode, adj, bobVis, path, ans);
            path.pop_back();
        }
    }
}

int mostProfitPath(int node, int ind, vector<int> adj[], vector<int> &amount, vector<int> aliceVis, vector<int> &bobPath){
    aliceVis[node] = 1;

    int cost = amount[node];
    if(ind < bobPath.size() && node == bobPath[ind]) cost = cost / 2;
    else {
        for(int i = 0; i <= ind; i++){
            if(node == bobPath[i]) cost = 0;
        }
    }

    int maxProfit = -1e9;

    int c = 0;
    for(int adjNode : adj[node]){
        if(!aliceVis[adjNode]){
            c++;
            int profit = cost + mostProfitPath(adjNode, ind + 1, adj, amount, aliceVis, bobPath);
            maxProfit = max(maxProfit, profit);
        }
    }
    if(c == 0) return cost;

    return maxProfit;
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = edges.size() + 1; // nodes in graph
    vector<int> adj[n];

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> aliceVis(n, 0);
    vector<int> bobVis(n, 0);
    vector<int> ans;
    vector<int> path;
    path.push_back(bob);
    bobPath(bob, adj, bobVis, path, ans);
    for(int a : ans){
        cout << a << " ";
    }

    return mostProfitPath(0, 0, adj, amount, aliceVis, ans);
}




int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    int res = mostProfitablePath(edges, bob, amount);
    cout << res << endl;
    return 0;
}