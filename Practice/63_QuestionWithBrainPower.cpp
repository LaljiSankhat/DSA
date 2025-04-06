#include <bits/stdc++.h>
using namespace std;


// leetcode 2140. Solving Questions With Brainpower

long long f(int i, vector<vector<int>> &questions){
    if(i >= questions.size()) return 0; // base case

    // take the question 
    long long take = questions[i][0] + f(i + questions[i][1] + 1, questions);
    long long notTake = 0;
    notTake = f(i + 1, questions);
    return max(take, notTake);
}

// memoization 
long long fDp(int i, vector<vector<int>> &questions, vector<long long> &dp){
    if(i >= questions.size()) return 0; // base case
    if(dp[i] != -1) return dp[i]; // check if already calculated

    // take the question 
    long long take = questions[i][0] + fDp(i + questions[i][1] + 1, questions, dp);
    long long notTake = 0;
    notTake = fDp(i + 1, questions, dp);
    return dp[i] = max(take, notTake);
}

// tabulation

long long ftab(vector<vector<int>> &questions){
    int n = questions.size();

    vector<long long> dp(n + 1, 0); // dp array for tabulation

    for(int i = n - 1; i >= 0; i--){
        long long take = questions[i][0] + dp[min(i + questions[i][1] + 1, n)];
        long long notTake = dp[i + 1];
        dp[i] = max(take, notTake);
    }

    return dp[0];
}

long long maxPoints(vector<vector<int>>& questions){
    int n = questions.size(); 
    vector<long long> dp(n + 1, -1); // dp array for memoization
    return fDp(0, questions, dp); // uncomment this line for memoization
    // return f(0, questions); // start from the first question
}


int main(){
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << maxPoints(questions) << endl; // Output: 7
    return 0;
}