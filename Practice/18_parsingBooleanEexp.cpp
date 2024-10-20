#include <bits/stdc++.h>
using namespace std;


/*

    1106. Parsing A Boolean Expression
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

*/


bool parseBoolean(string expression){
    int n = expression.size();
    stack<char> operation;
    stack<int> operands;

    for(int i = 0; i < n; i++){
        char ch = expression[i];
        if(ch == '(' || ch == 't' || ch == 'f') {
            if(ch == '(') operands.push(-1);
            else if(ch == 't') operands.push(1);
            else operands.push(0);
        }
        else if(ch == '!' || ch == '&' || ch == '|') operation.push(ch);
        else if (ch == ')'){
            if(!operation.empty() && operation.top() == '!'){
                operation.pop();
                int t = operands.top();
                operands.pop();
                operands.pop();
                operands.push(!t);
            } else {
                char op = operation.top();
                operation.pop();
                int result = operands.top();
                operands.pop();

                while (!operands.empty() && operands.top() != -1) {
                    int b = operands.top();
                    operands.pop();
                    if (op == '&') result = result & b;
                    else result = result | b;
                }
                operands.pop();
                operands.push(result); 
            }
        }
    }

    if(operands.top() == 1) return 1;
    return 0;
}


int main(){
    string expression = "!(&(f,t))";
    cout << parseBoolean(expression);
    return 0;
}