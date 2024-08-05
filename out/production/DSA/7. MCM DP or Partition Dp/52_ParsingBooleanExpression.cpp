#include <bits/stdc++.h>
using namespace std;


/*
    Problem statement
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), 
and operators will be : (AND, OR or XOR).
Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007.

Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
*/

/*
    To solve these as usual we start with the problem with indexes i to j
    if i == j then total numbers of ways in which it return true or false is 1.
    now we know that first start with T/F then we have operation, so at every second position we have operation
    so for partition we run loop by increasing twice.
    then we get two subproblems, here we want answer as true so according to operation we have cases
    let operation is AND
    then if left will return x numbers of ways in which it makes true
    and right return the y numbers of ways in which it will return the true
    then total no of ways in which i to j will make true is x * y
    IF operation is XOR then cases of T - F and F - T
    IF operation is OR thne cases will be T - F and F -T.
*/

int parseBooleanExpression(int i, int j, int isTrue, string &s){
    if(i > j) return 0;
    if(i == j){
        if(isTrue == 1) return s[i] == 'T';
        else return s[i] == 'F';
    }

    // explore all posibilities
    int ways = 0;
    for(int ind = i + 1; ind <= j; ind = ind + 2){
        int leftTrue = parseBooleanExpression(i, ind - 1, 1, s);
        int leftFalse = parseBooleanExpression(i, ind - 1, 0, s);
        int rightTrue = parseBooleanExpression(ind + 1, j, 1, s);
        int rightFalse = parseBooleanExpression(ind + 1, j, 0, s);
        if(s[i] == '&'){
            if(isTrue == 1) ways += leftTrue * rightTrue;
            else ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
        } else if(s[i] == '|'){
            if(isTrue == 1) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
            else ways += leftFalse * rightFalse;    
        } else {
            if(isTrue == 1) ways += (leftTrue * rightFalse) + (rightTrue * leftFalse);
            else ways += (leftTrue * rightTrue) + (leftFalse + rightFalse);
        }
    }

    return ways;
}

// memization
int parseBooleanExpressionDp(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
    if(i > j) return 0;
    if(i == j){
        if(isTrue == 1) return dp[i][i][isTrue] = (s[i] == 'T');
        else return dp[i][i][isTrue] = (s[i] == 'F');
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    // explore all posibilities
    int ways = 0;
    for(int ind = i + 1; ind <= j; ind = ind + 2){
        int leftTrue = parseBooleanExpressionDp(i, ind - 1, 1, s, dp);
        int leftFalse = parseBooleanExpressionDp(i, ind - 1, 0, s, dp);
        int rightTrue = parseBooleanExpressionDp(ind + 1, j, 1, s, dp);
        int rightFalse = parseBooleanExpressionDp(ind + 1, j, 0, s, dp);
        if(s[i] == '&'){
            if(isTrue == 1) ways += leftTrue * rightTrue;
            else ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
        } else if(s[i] == '|'){
            if(isTrue == 1) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
            else ways += leftFalse * rightFalse;    
        } else {
            if(isTrue == 1) ways += (leftTrue * rightFalse) + (rightTrue * leftFalse);
            else ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
        }
    }

    return dp[i][j][isTrue] = ways;
}


// tabulation
int parseBooleanExpressionTab(string &s){
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= n - 1; j++){
            for(int isTrue = 0; isTrue <= 1; isTrue++){
                if(i > j) continue;
                if(i == j){
                    if(isTrue) dp[i][i][isTrue] = (s[i] == 'T');
                    else dp[i][i][isTrue] = (s[i] == 'F');
                    continue;
                }
                int ways = 0;
                for (int ind = i + 1; ind < j; ind = ind + 2)
                {
                    int leftTrue = dp[i][ind - 1][1];
                    int leftFalse = dp[i][ind - 1][0];
                    int rightTrue = dp[ind + 1][j][1];
                    int rightFalse = dp[ind + 1][j][0];
                    if (s[i] == '&')
                    {
                        if (isTrue == 1)
                            ways += leftTrue * rightTrue;
                        else
                            ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);
                    }
                    else if (s[i] == '|')
                    {
                        if (isTrue == 1)
                            ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
                        else
                            ways += (leftFalse * rightFalse);
                    }
                    else
                    {
                        if (isTrue == 1)
                            ways += (leftTrue * rightFalse) + (rightTrue * leftFalse);
                        else
                            ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][1];
}   

int main(){
    string a = "T|T|T";
    int n = a.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    cout << parseBooleanExpression(0, n - 1, 1, a) << endl;
    cout << parseBooleanExpressionDp(0, n - 1, 1, a, dp) << endl;
    cout << parseBooleanExpressionTab(a) << endl;
    return 0;
}