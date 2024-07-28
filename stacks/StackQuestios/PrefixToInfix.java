package StackQuestios;

import java.util.Stack;

public class PrefixToInfix {
    public static void main(String[] args) {
        String prefix = "-8/*+5346";
        System.out.println(prefix);
        Stack<String> val = new Stack<>();
        for(int i = prefix.length()-1; i >= 0 ; i--){
            char ch = prefix.charAt(i);
            int ascii = (int)ch;
            if(ascii <= 57 && ascii >= 48){
                String s = "" + ch;
                val.push(s);
            }
            else{
                String v1 = val.pop();
                String v2 = val.pop();
                String s1 = '(' + v1 + ch + v2 + ')';
                val.push(s1);
            }
        }
        String infix = val.pop();
        System.out.println(infix);
    }
}
