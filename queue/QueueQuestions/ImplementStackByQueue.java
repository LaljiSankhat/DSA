package QueueQuestions;

import java.util.LinkedList;
import java.util.Queue;

class MyStack {
    Queue<Integer> q = new LinkedList<>();

    public void push(int val) {
        q.add(val);
    }
    public int peek(){
        if(q.size() == 0){
            System.out.println("Stack is empty");
            return -1;
        }
        for(int i = 0; i < q.size() -1; i++){
            q.add(q.remove());
        }
        int x = q.remove();
        q.add(x);
        return x;
    }
    public int remove(){
        if(q.size() == 0){
            System.out.println("Stack is empty");
            return -1;
        }
        for(int i = 0; i < q.size() -1; i++){
            q.add(q.remove());
        }
        int x = q.remove();
        return x;        
    }
    public boolean isEmpty(){
        return q.isEmpty();
    }

}

// better solution 
/*
 * public class MyStack {
    private Queue<Integer> q;

    public MyStack() {
        q = new LinkedList<>();
    }

    public void push(int x) {
        q.add(x);
        for (int i = 1; i < q.size(); i++) {
            q.add(q.remove());
        }
    }

    public int pop() {
        return q.remove();
    }

    public int top() {
        return q.peek();
    }

    public boolean empty() {
        return q.isEmpty();
    }
}
 */

public class ImplementStackByQueue {
    public static void main(String[] args) {

    }
}
