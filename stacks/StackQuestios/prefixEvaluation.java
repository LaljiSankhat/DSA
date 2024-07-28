package StackQuestios;

import java.util.Stack;

public class prefixEvaluation {
    public static void main(String[] args) {
        String prefix = "-8/*+5346"; // 8-(5+3)*4/6
        Stack<Integer> val = new Stack<>();
        for(int i = prefix.length() - 1 ; i >= 0; i--){
            char ch = prefix.charAt(i);
            int ascii = (int)ch;
            // ascii values of '0' --> 48  '9' --> 57
            if(ascii <= 57 && ascii >= 48){
                val.push(ascii - 48);
            }
            else{
                int v1 = val.pop();
                int v2 = val.pop();
                if(ch == '+') val.push(v1 + v2);
                if(ch == '-') val.push(v1 - v2);
                if(ch == '*') val.push(v1 * v2);
                if(ch == '/') val.push(v1 / v2);
            }
        }
        System.out.println(val.peek());
    }
}
