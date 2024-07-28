#include <bits/stdc++.h>
using namespace std;

// this is different but similar
/*
    207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false. 

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique
*/


/*
    question is to detect cycle in graph
*/
/* 
    To solve this we use bfs with parent node 
    now if we go to the adjacent node,
    if it is not visited then visit it and push into queue
    if it is visited then if it is not parent then how it's being visited by whome, 
    so there is another node who visits that node,  
    now current node also want to visit so there is CYCLE
*/


#include <bits/stdc++.h>
using namespace std;

void generateGraph(int n, int m, vector<int> adj[]){
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {1, 3},
        {3, 4},
        {2, 4},
        {4, 5}
    };
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool detectCycle(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            } else if(parent != adjacentNode){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(vector<int> adj[], int v){

    int vis[v] = {0};

    for(int i = 0; i < v; i++){
        if(!vis[i]) {
            if(detectCycle(i, adj, vis)) return true;
        }
    }

    return false;
}


int main(){
    int n = 6;
    int m = 6;
    vector<int> adj[n + 1];
    generateGraph(n, m , adj);

    cout << isCycle(adj, n) << endl;

    // TC = O(v + 2E) (becuse we traverse in adj list so simple bfs) (here we do not multiply O(n) of looop becuase not every 
    // calll happen so we add it but not multiply it)
    // SC = O(V) (queue can have all nodes) + O(V) (for visited)
    
    return 0;
}