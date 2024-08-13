#include <bits/stdc++.h>
using namespace std;


/*
    Number Of Islands
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations.
Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is 
no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you 
can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after 
each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side. 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
*/


class DisjoinSet{
    vector<int> rank, parent, size;

    public:
    DisjoinSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) 
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else { // rank are same
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    
    // so here we are doing path compression so rank will not tell about height so why not we use size istead of rank

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); // ultimate parent of u
        int ulp_v = findUPar(v); // ultimate parent of v
        if(ulp_u == ulp_v) return; // if in the same component no need to go furthur
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else { // if it is greater or same in both case we will be attach and increase size 
            // in same case we can attach any to any so no need for extra case
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        
    }
};



vector<int> noOfIslandsII(int n, int m, vector<vector<int>> &operators){
    DisjoinSet ds(n * m);
    int vis[n][m];
    memset(vis, 0, sizeof vis); // mark all as zero
    int cnt = 0;
    vector<int> ans;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(auto it : operators){
        int row = it[0];
        int col = it[1];
        int node = m * row + col;
        if(vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;

        cnt = cnt + 1;

        for(int i = 0; i < 4; i++){
            int adjRow = row + drow[i];
            int adjCol = col + dcol[i];
            if(adjRow < n && adjRow >= 0 && adjCol < m && adjCol >= 0 && vis[adjRow][adjCol] == 1){
                int adjNode = m * adjRow + adjCol;
                if(ds.findUPar(node) != ds.findUPar(adjNode)){
                    cnt = cnt - 1;
                    ds.unionBySize(node, adjNode);
                }
            }
        }

        ans.push_back(cnt);
        
    }


    return ans;
}



int main(){
    int n = 4;
    int m = 5;
    vector<vector<int>> operators = {{1,1},{0,1},{3,3},{3,4}};

    vector<int> ans = noOfIslandsII(n, m, operators);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}