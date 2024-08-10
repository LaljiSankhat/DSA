#include <bits/stdc++.h>
using namespace std;


/*
    840. Magic Squares In Grid
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, 
column, and both diagonals all have the same sum.
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
*/

bool isValid(int i, int j, vector<vector<int>> &grid){
    // check for middle elem is 5
    if(grid[i + 1][j + 1] != 5) return false;

    // checking all numbers are unique and between 1 to 9
    set<int> st;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            int num = grid[i + x][j + y];
            if(num < 1 || num > 9) return false;
            st.insert(num);
        }
    }

    if(st.size() != 9) return false;

    // Compute the sums of rows, columns, and diagonals
    int rowSum1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    int rowSum2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
    int rowSum3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

    int colSum1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
    int colSum2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
    int colSum3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

    int diagSum1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
    int diagSum2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

    // Check if all sums are equal to 15
    return (rowSum1 == 15 && rowSum2 == 15 && rowSum3 == 15 &&
            colSum1 == 15 && colSum2 == 15 && colSum3 == 15 &&
            diagSum1 == 15 && diagSum2 == 15);
}

int magicSquares(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    // all possible 3 * 3 matrices
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + 2 < n && j + 2 < m){
                if(isValid(i, j, grid)){
                    cnt++;
                }
            }
        }
    }

    return cnt;
}


int main(){
    vector<vector<int>> grid = {
        {4,3,8,4},
        {9,5,1,9},
        {2,7,6,2}
    };

    cout << magicSquares(grid);
    return 0;
}