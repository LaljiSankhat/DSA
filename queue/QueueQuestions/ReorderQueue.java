package QueueQuestions;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class ReorderQueue {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        q.add(6);
        q.add(7);
        q.add(8);
        System.out.println(q);
        // Stack<Integer> st = new Stack<>();
        // Stack<Integer> gt = new Stack<>();
        // Stack<Integer> h = new Stack<>();
        // while(q.size() != 4){
        //     h.push(q.remove());
        // }
        // while(h.size() != 0){
        //     st.push(h.pop());
        // }
        // while(q.size() != 0){
        //     h.push(q.remove());
        // }
        // while(h.size() != 0){
        //     gt.push(h.pop());
        // }
        // while(st.size() != 0){
        //     q.add(st.pop());
        //     q.add(gt.pop());
        // }
        // System.out.println(q);

        // method 2 by only one stack

        Stack<Integer> st = new Stack<>();
        int n = (q.size())/2;
        for(int i = 0; i < n; i++){ // first half to stack
            st.push(q.remove());
        }
        System.out.println(q);
        while(st.size() != 0){ // add to queue with reverse order
            q.add(st.pop());
        }
        System.out.println(q);
        for(int i = 0; i < n; i++){// addind sencond half to queue
            st.push(q.remove());
        }
        System.out.println(q);
        while(st.size() != 0){//add to queue with reverse order of second half
            q.add(st.pop());
            q.add(q.remove());
        }
        System.out.println(q);
        // hence our output is reversed so we need to forward it by queue and stack
        for(int i = 0; i< (n*2); i++){
            st.push(q.remove());
        }
        while(st.size() != 0){
            q.add(st.pop());
        }
        System.out.println(q);

    }
}
