package StackQuestios;


// Extension of question 1 for string contains of [ { also

import java.util.Scanner;
import java.util.Stack;

public class q3 {
    public static boolean validBrackets(String s){
        Stack<Character> st1 = new Stack<>();
        Stack<Character> st2 = new Stack<>();
        Stack<Character> st3 = new Stack<>();
        int n = s.length();
        for(int i =0;i<n;i++){
            char a = s.charAt(i);
            if(a == '(' || a== ')'){
                if(a == '('){
                    st1.push(a);
                }
                else{
                    if(st1.isEmpty()) return false;
                    else st1.pop();
                }
            }
            else if(a == '{' || a == '}'){
                if(a == '{'){
                    st2.push(a);
                }
                else{
                    if(st2.isEmpty()) return false;
                    else st2.pop();
                }
            }
            else{
                if(a == '['){
                    st3.push(a);
                }
                else{
                    if(st3.isEmpty()) return false;
                    else st3.pop();
                }
            }
        }
        return st1.isEmpty() && st2.isEmpty() && st3.isEmpty();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter string");
        String s = sc.nextLine();
        boolean a = validBrackets(s);
        System.out.println(a);
        sc.close();
    }
}
