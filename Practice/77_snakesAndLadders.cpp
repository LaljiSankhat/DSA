#include <bits/stdc++.h>
using namespace std;


// leetcode 909. Snakes and Ladders


int snakesAndLadders(vector<vector<int>>& board) {
    // first get all indexes from board for traversal
    int n = board.size(), lbl = 1;
    vector<pair<int, int>> cells(n * n + 1);
    vector<int> columns(n);
    for(int i = 0; i < n; i++){
        columns[i] = i;
    }
    for(int row = n - 1; row >= 0; row--){
        for(int column : columns){
            cells[lbl++] = {row, column};
        }
        reverse(columns.begin(), columns.end());
    }

    vector<int> dist(n * n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next = curr + 1; next <= min(curr + 6, n * n); next++){
            int row = cells[next].first;
            int column = cells[next].second;
   
            int destination = board[row][column] != -1 ? board[row][column] : next;
            if(dist[destination] == -1){
                dist[destination] = dist[curr] + 1;
                q.push(destination);
            }
        }
    }


    return dist[n * n];
}



int main(){
    vector<vector<int>> matrix = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    cout << snakesAndLadders(matrix) << endl;
    return 0;
}