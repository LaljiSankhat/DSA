#include <bits/stdc++.h>
using namespace std;


/*
    207. Course Schedule I
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
course bi first if you want to take course ai.
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
All the pairs prerequisites[i] are unique.
*/

// so here concept of someone before someone so we apply topo sort
// if there is no cyclic dependecy then it will return true

bool canFinishCourses(int v, vector<vector<int>> &graph){
    vector<int> adj[v];
    int n = graph.size();

    for(int i = 0; i < n; i++){
        adj[graph[i][0]].push_back(graph[i][1]); 
    }

    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto adjacentNode : adj[node]) {
            indegree[adjacentNode]--;
            if (indegree[adjacentNode] == 0) {
                q.push(adjacentNode);
            }
        }
    }

    if (ans.size() == v) return true;
    return false;
}


// for courses II we need to return the ordrer in which task can pe performend or courses can be taken
// also in this question dependency also changed that if you take first course first you have to finish second course

vector<int> giveOrderOfCourses(int v, vector<vector<int>> &graph){
    vector<int> adj[v];
    int n = graph.size();

    for(int i = 0; i < n; i++){
        adj[graph[i][1]].push_back(graph[i][0]); 
    }

    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto adjacentNode : adj[node]) {
            indegree[adjacentNode]--;
            if (indegree[adjacentNode] == 0) {
                q.push(adjacentNode);
            }
        }
    }

    
    if(ans.size() == v) return ans;
    return {};
}


int main(){
    int n = 6;
    vector<vector<int>> graph = {{1, 0}, {0, 1}};

    cout << canFinishCourses(n, graph) << endl;
    
    return 0;
}