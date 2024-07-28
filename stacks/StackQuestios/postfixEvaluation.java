package StackQuestios;

import java.util.Stack;

public class postfixEvaluation {
    public static void main(String[] args) {
        String postfix = "853+4*6/-";
        Stack<Integer> val = new Stack<>();
        for(int i = 0; i < postfix.length(); i++){
            char ch = postfix.charAt(i);
            int ascii = (int)ch;
            // ascii values of '0' --> 48  '9' --> 57
            if(ascii <= 57 && ascii >= 48){
                val.push(ascii - 48);
            }
            else{
                int v2 = val.pop();
                int v1 = val.pop();
                if(ch == '+') val.push(v1 + v2);
                if(ch == '-') val.push(v1 - v2);
                if(ch == '*') val.push(v1 * v2);
                if(ch == '/') val.push(v1 / v2);
            }
        }
        System.out.println(val.peek());
    }
}
