package StackQuestios;

import java.util.Stack;

public class infixWithParenthesis {
    public static void main(String[] args) {
        String str = "2+(5+3)*4";
        Stack<Integer> val2 = new Stack<>();
        Stack<Character> op2 = new Stack<>();
        for(int i = 0 ; i< str.length(); i++){
            char ch = str.charAt(i);
            int ascii = (int)ch;
            // ascii values of '0' --> 48  '9' --> 57
            if(ascii <= 57 && ascii >= 48){
                val2.push(ascii - 48);
            }
            else if(op2.size() == 0 || ch ==  '(' || op2.peek() == '('){
                op2.push(ch);
            }
            else if(op2.peek() == ')'){
                while(op2.peek() != '('){
                    int v2 = val2.pop();
                    int v1 = val2.pop();
                    if(op2.peek() == '-') val2.push(v1 - v2);
                    if(op2.peek() == '+') val2.push(v1 + v2);
                    if(op2.peek() == '*') val2.push(v1 * v2);
                    if(op2.peek() == '/') val2.push(v1 / v2);
                    op2.pop();
                }
                op2.pop();
            }
            else{
                if(ch == '+' || ch == '-'){
                    // work niptao
                    int v2 = val2.pop();
                    int v1 = val2.pop();
                    if(op2.peek() == '-') val2.push(v1 - v2);
                    if(op2.peek() == '+') val2.push(v1 + v2);
                    if(op2.peek() == '*') val2.push(v1 * v2);
                    if(op2.peek() == '/') val2.push(v1 / v2);
                    op2.pop();
                    op2.push(ch);
                }
                else if(ch == '*' || ch == '/'){
                    if(op2.peek() == '*' || op2.peek() == '/'){
                        int v2 = val2.pop();
                        int v1 = val2.pop();
                        if(op2.peek() == '*') val2.push(v1 * v2);
                        if(op2.peek() == '/') val2.push(v1 / v2);
                        op2.pop();
                        op2.push(ch);
                    }
                    else op2.push(ch);
                }
            }
        }
        while(val2.size() > 1){
            // work2
            int v2 = val2.pop();
            int v1 = val2.pop();
            if(op2.peek() == '-') val2.push(v1 - v2);
            if(op2.peek() == '+') val2.push(v1 + v2);
            if(op2.peek() == '*') val2.push(v1 * v2);
            if(op2.peek() == '/') val2.push(v1 / v2);
            op2.pop();
        }
        System.out.println(val2.peek());
    }
}
