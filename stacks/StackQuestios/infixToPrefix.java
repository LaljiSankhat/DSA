package StackQuestios;

import java.util.Stack;

public class infixToPrefix {
    public static void main(String[] args) {
//        String infix = "1/(8+5)*8";
        String infix = "8-(5+3)*4/6";
        Stack<String> val = new Stack<>();
        Stack<Character> op = new Stack<>();
        for(int i = 0; i < infix.length(); i++){
            char ch = infix.charAt(i);
            int ascii = (int)ch;
            // ascii values of '0' --> 48  '9' --> 57
            if(ascii <= 57 && ascii >= 48){
                String s = "" + ch;
//                val.push(ascii - 48);
                val.push(s);
            }
            else if(op.size() == 0 || ch ==  '(' || op.peek() == '('){
                op.push(ch);
            }
            else if(ch == ')'){
                while (op.peek() != '('){
                    // work
                    char o = op.pop();
                    String v2 = val.pop();
                    String v1 = val.pop();
                    String s1 = o + v1 + v2;
                    val.push(s1);
                }
                op.pop();
            }
            else{
                if(ch == '+' || ch == '-'){
                    // work
                    char o = op.pop();
                    String v2 = val.pop();
                    String v1 = val.pop();
                    String s1 = o + v1 + v2;
                    val.push(s1);
                    op.push(ch);
                }
                if(ch == '/' || ch == '*'){
                    if(op.peek() == '*' || op.peek() == '/'){
                        //work
                        char o = op.pop();
                        String v2 = val.pop();
                        String v1 = val.pop();
                        String s1 = "" + o + v1 + v2;
                        val.push(s1);
                        op.push(ch);
                    }
                    else op.push(ch);
                }
            }
        }
        while(val.size() > 1){
            // work
            char o = op.pop();
            String v2 = val.pop();
            String v1 = val.pop();
            String s1 = o + v1 + v2;
            val.push(s1);
        }
        String prefix = val.pop();
        System.out.println(prefix);
    }
}
