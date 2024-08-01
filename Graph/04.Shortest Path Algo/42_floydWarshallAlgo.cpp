#include <bits/stdc++.h>
using namespace std;


/*
    Floyd Warshall
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. 
If Matrix[i][j]=-1, it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.

Examples :
Input: matrix = [[0, 25],[-1, 0]]

Output: [[0, 25],[-1, 0]]

Explanation: The shortest distance between every pair is already given(if it exists).
*/

// bell ford will give path for src to every node we have find the each path from any node to any node 
// so we use floyd warshall algorithm
// also use to detect -ve cycle

// Note: go via all the nodes and set minimum
// so we iterate on all node find dist i to j via k node
// dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j])
// so we three loops via -> i -> j

// how to detect -ve cycle ?
// for this if we get dist of node to node itself as -ve then there is a -ve cycle
// becuse dist of node to node itself is 0

void floydWarshallAlgo(vector<vector<int>> &matrix){
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                // before going if not reachable assign it to infinity
                matrix[i][j] = 1e9;
            }
            if(i == j) matrix[i][j] = 0;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // to check for -ve cycles 
    for(int i = 0; i < n; i++){
        if(matrix[i][i] != 0) {
            cout << "there is a -ve cycle in the graph" << endl;
            return;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1e9){
                // before reurning if infinityassign it to -1
                matrix[i][j] = -1;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {0, 25},
        {-1, 0}
    };

    floydWarshallAlgo(matrix);
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}