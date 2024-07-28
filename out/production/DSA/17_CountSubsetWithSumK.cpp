#include <bits/stdc++.h>
using namespace std;


/*
Problem statement
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.

Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

Example:
Input: 'arr' = [1, 1, 4, 5] target: 5

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.

Sample Input 2 :
3  target : 2
1 1 1
Sample Output 2 :
3
Explanation For Sample Output 1:
There are three 1 present in the array. Answer is the number of ways to choose any two of them.

Sample Input 3 :
3 target : 40
2 34 5
Sample Output 3 :
0

Expected time complexity :
The expected time complexity is O('n' * 'k').
Constraints:
1 <= 'n' <= 100
0 <= 'arr[i]' <= 1000
1 <= 'k' <= 1000
Time limit: 1 sec
*/

/* this is also same as Q.14 but here we have to count so we have to sum all the fn calls and return it */

int countSubSets(int ind, vector<int> &arr, int sum){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    int pick = 0;
    if(sum >= arr[ind]) pick = countSubSets(ind - 1, arr, sum - arr[ind]);
    int notPick = countSubSets(ind - 1, arr, sum);

    return pick + notPick;
}

// memoization
int countSubSetsDp(int ind, vector<int>& arr, int sum, vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];

    int pick = 0;
    if(sum >= arr[ind]) pick = countSubSetsDp(ind - 1, arr, sum - arr[ind], dp);
    int notPick = countSubSetsDp(ind - 1, arr, sum, dp);

    return dp[ind][sum] = pick + notPick;
}

// Tabulation
int countSubSetsTab(vector<int> &arr, int sum, vector<vector<int>> &dp){
    // basecases
    int n = arr.size();
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(arr[0] <= sum) dp[0][arr[0]] = 1;
    dp[0][0] = 2;

    // changing states
    for(int i = 1; i < n; i++){
        for(int s = 0; s <= sum; s++){
            int pick = 0;
            if(s >= arr[i]) pick = dp[i - 1][s - arr[i]];
            int notPick = dp[i - 1][s];
            dp[i][s] = pick + notPick;
        }
    }

    //return part
    return dp[n - 1][sum];
}

// Space optimization
int countSubSetsSpace(vector<int> &arr, int sum){
    int n = arr.size();
    vector<int> prev(sum + 1, 0), cur(sum + 1);
    prev[0] = cur[0] = 1;
    if(arr[0] <= sum) prev[arr[0]] = 1;

    // changing states
    for(int i = 1; i < n; i++){
        for(int s = 0; s <= sum; s++){
            int pick = 0;
            if(s >= arr[i]) pick = prev[s - arr[i]];
            int notPick = prev[s];
            cur[s] = pick + notPick;
        }
        prev = cur;
    }

    //return part
    return prev[sum];
}

int main(){
    vector<int> arr = {1,4,4,5};
    int sum = 5;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << countSubSets(n - 1, arr, sum) << endl;
    cout << countSubSetsDp(n - 1, arr, sum, dp) << endl;
    cout << countSubSetsTab(arr, sum, dp) << endl;
    cout << countSubSetsSpace(arr, sum) << endl;
    return 0;
}