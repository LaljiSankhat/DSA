#include <bits/stdc++.h>
using namespace std;


/*
Problem statement
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.
Note that the sum of the elements of an empty subset is 0.

For example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

The first line of each test case contains two space-separated integers, ‘N’ and ‘D,’ denoting the number of elements in the array and the desired difference.

The following line contains N integers denoting the space-separated integers ‘ARR’.
Output Format :
For each test case, find the number of partitions satisfying the above conditions modulo 10^9 + 7.
Output for each test case will be printed on a separate line.
Note :
You are not required to print anything; it has already been taken care of. Just implement the function.
Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 50
0 ≤ D ≤ 2500
0 ≤ ARR[i] ≤ 50

Sample Input 1 :
2
4 3
5 2 6 4
4 0
1 1 1 1
Sample Output 1 :
1
6
Explanation For Sample Input 1 :
For test case 1:
We will print 1 because :
There is only one possible partition of this array.
Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3

For test case 2:
We will print 6 because :
The partition {1, 1}, {1, 1} is repeated 6 times:
Partition 1 : {ARR[0], ARR[1]}, {ARR[2], ARR[3]}
Partition 2 : {ARR[0], ARR[2]}, {ARR[1], ARR[3]}
Partition 3 : {ARR[0], ARR[3]}, {ARR[1], ARR[2]}
Partition 4 : {ARR[1], ARR[2]}, {ARR[0], ARR[3]}
Partition 5 : {ARR[1], ARR[3]}, {ARR[0], ARR[2]}
Partition 6 : {ARR[2], ARR[3]}, {ARR[0], ARR[1]}
The difference is in the indices chosen for the subset S1(or S2).
Sample Input 2 :
3
3 1
4 6 3
5 0
3 1 1 2 1
5 1
3 2 2 5 1
Sample Output 2 :
1
6
3
*/

/* this is as same as Q.14 but we have to identify the target or sum 
so  D = S1 - S2
 We know that S1 + S2 = TotalSum
 sp S1 = totalSum - S2

 so D = (totalSum - S2) - S2
    D = TS - 2S2
    S2 = (totalSum - D) / 2;
     
     so we kindly replace sum with this totalSum and we get the answer
 */


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
    if(arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

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
    if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

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

int countSubSetsWithDiff(vector<int> &arr, int D){
    int n = arr.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    if(totalSum - D < 0 || ((totalSum - D) % 2)) return 0;
    int sum = (totalSum - D) / 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    return countSubSetsSpace(arr, sum);
}

int main(){
    vector<int> arr = {5,2,6,4};
    int D = 3;
    cout << countSubSetsWithDiff(arr, D) << endl;
    return 0;
}