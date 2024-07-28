package QueueQuestions;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class ReverseKElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        System.out.println(q);
        Stack<Integer> st = new Stack<>();
        System.out.println("Enter value of k");
        int k = sc.nextInt();
        for(int i = 0; i< k; i++){
            int x = q.remove();
            st.push(x);
        }
        while(st.size() != 0){
            q.add(st.pop());
        }
        for(int i = 0; i < q.size() - k; i++){
            int a = q.remove();
            q.add(a);
        }
        System.out.println(q);
        sc.close();
    }
}
