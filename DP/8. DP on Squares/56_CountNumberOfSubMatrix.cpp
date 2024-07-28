#include <bits/stdc++.h>
using namespace std;


/*
    1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

/*
    So in this question we have given a matrix with all etries are either 1 or 0; 
    we have to find number of submatrix that are squares and all entries in that is 1;
*/

int countSquares(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i = 0; i < m; i++) dp[0][i] = matrix[0][i];
    for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    int totalSqaures = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            totalSqaures += dp[i][j];
        }
    }

    return totalSqaures;
}


int main(){
    vector<vector<int>> matrix = {{1,0,1}, {1,1,0}, {1,1,0}};
    cout << countSquares(matrix) << endl;
    return 0;
}