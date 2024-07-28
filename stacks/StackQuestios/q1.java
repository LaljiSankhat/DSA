package StackQuestios;

import java.util.Scanner;
import java.util.Stack;

// balanced bracket string
// if opening ( then push
// if ) --> if stack empty return false else pop
// if stack is not empty return false
public class q1 {
    public static boolean balancedBrackets(String s){
        Stack<Character> st = new Stack<Character>();
        int n = s.length();
        for(int i = 0; i<n ; i++){
            char a = s.charAt(i);
            if(a == '('){ // if opening ( then push
                st.push('(');
            } else{
                if(st.isEmpty()) return false; //if stack empty return false
                else{ //else pop
                    st.pop();
                }
            }
        }
        return st.isEmpty(); // if stack is not empty return false
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter string of brackets");
        String s = sc.next();
        boolean x = balancedBrackets(s);
        System.out.println(x);
        sc.close();
    }
}
