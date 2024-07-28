#include <bits/stdc++.h>
using namespace std;


/*
    Replace O's with X's
Difficulty: MediumAccuracy: 34.0%Submissions: 104K+Points: 4
Given a matrix mat of size N x M where every element is either 'O' or 'X'. 
Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at 
locations just below, just above, just left and just right of it.

Example 1:
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 

Example 2:
Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix
*/

// similar leetcode question 130. Surrounded Regions

// we apply dfs here on boundary 'O's becuase group of 'O's which touches the boundary cannot be surounded

void dfs(int i, int j, vector<vector<char>> &board, vector<vector<char>> &ans, vector<vector<int>> &vis){
    vis[i][j] = 1;
    ans[i][j] = 'O';
    int n = board.size();
    int m = board[0].size();

    int drow[] = {-1, 0, 1, 0};        
    int dcol[] = {0, 1, 0, -1};    

    for(int k = 0; k < 4; k++){
        int nrow = i + drow[k];
        int ncol = j + dcol[k];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow, ncol, board, ans, vis);
        }
    }
}


vector<vector<char>> replaceOsWithX(vector<vector<char>> &board, int n, int m){
    vector<vector<char>> ans(n, vector<char>(m, 'X'));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                if(board[i][j] == 'O' && !vis[i][j]){
                    dfs(i, j, board, ans, vis);
                }
            }
        }
    }

    return ans;

    // to replace in board we can do diresct replace with ans values 
    // or we can put X in where vis == 0 and put O where vis == 1
    // becuase we only visited the boundary Os
}


int main(){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, 
                                  {'X', 'O', 'X', 'X'}, 
                                  {'X', 'O', 'O', 'X'}, 
                                  {'X', 'O', 'X', 'X'}, 
                                  {'X', 'X', 'O', 'O'}};
    int n = 5;
    int m = 4;

    vector<vector<char>> result = replaceOsWithX(board, n, m);
    for(const auto &row : result) {
        for(const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // TC = O(N * M * 4) (at worst we can call for all and for each we have 4 direction + O(n) for loop of boundary
    // SC = O(N * M) + O(n * m) (for ans and vis) + O(N * M) (recurstion stack space)
    return 0;
}