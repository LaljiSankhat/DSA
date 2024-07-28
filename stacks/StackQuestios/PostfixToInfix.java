package StackQuestios;

import java.util.Stack;

public class PostfixToInfix {
    public static void main(String[] args) {
        String postfix = "853+4*6/-";
        System.out.println(postfix);
        Stack<String> val = new Stack<>();
        for(int i = 0; i < postfix.length(); i++){
            char ch = postfix.charAt(i);
            int ascii = (int)ch;
            if(ascii <= 57 && ascii >= 48){
                String s = "" + ch;
                val.push(s);
            }
            else{
                String v2 = val.pop();
                String v1 = val.pop();
                String s1 = '(' + v1 + ch + v2 + ')';
                val.push(s1);
            }
        }
        String infix = val.pop();
        System.out.println(infix);
    }
}
