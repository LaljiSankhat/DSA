package StackQuestios;

import java.util.Scanner;
import java.util.Stack;

// NO of brackets to be removed to  get balanced bracket
public class q2 {
    public static int noOfBrackets(String s){
        Stack<Character> st = new Stack<>();
        int count = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char ch = s.charAt(i);
            if(ch == '('){
                st.push(ch);
            }else{
                if(st.isEmpty()) count++;
                else st.pop();
            }
        }
        return count + st.size();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter string");
        String s = sc.nextLine();
        int a = noOfBrackets(s);
        System.out.println(a);
        sc.close();
    }
}
