#include <bits/stdc++.h>
using namespace std;


/*
    MCM : Matrix Chain Multiplication
    Problem statement
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient
way to multiply these matrices. In other words, determine where to place parentheses to 
minimize the number of multiplications.You will be given an array p[] of size n + 1.
Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
*/

/*
    Prtition Dp used when we have to solve problem through multiple partiontions.
    let's take example of 4 Matrices A, B, C, D
    we can multiply them using FIVE partitions
    1. (AB)(CD)
    2. (A(BC))D
    3. A((BC)D)
    4. ((AB)C)D
    5. A(B(CD))
*/

/* 
    Here we have given dimentions of matrices in nums array
    where dimention of ith matrix is nums[i - 1] X nums[i]
*/

/* 
    RULES for Partition dp problems
    1. Start with entire block/Array  (represent them by i, j  i.e. f(i, j))
    2. Try all partitions
    3. return the two best partitions like (AB)(CD)
*/

int matrixChainMultiplication(int i, int j, vector<int> &arr){
    // Base Case
    if(i == j) return 0;

    // Try all possible ways
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = (arr[i - 1] * arr[k] * arr[j]) 
                    + matrixChainMultiplication(i, k, arr) + matrixChainMultiplication(k + 1, j, arr);
        mini = min(mini, steps);    
    }

    return mini;
}

// Memoization
int matrixChainMultiplicationDp(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    // Base Case
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    // Try all possible ways
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = (arr[i - 1] * arr[k] * arr[j]) 
                    + matrixChainMultiplicationDp(i, k, arr, dp) + matrixChainMultiplicationDp(k + 1, j, arr, dp);
        mini = min(mini, steps);    
    }

    return dp[i][j] = mini;
}
// Here we have TC = O(N X N X N) extra N for every state we have a loop consider it as N loop
// SC = O(N^2) + O(n)

int main(){
    vector<int> arr = {10, 15, 20, 25};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << matrixChainMultiplication(1, n - 1, arr) << endl;
    cout << matrixChainMultiplicationDp(1, n - 1, arr, dp) << endl;
    return 0;
}