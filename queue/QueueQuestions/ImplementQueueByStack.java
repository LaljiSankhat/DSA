package QueueQuestions;

import java.util.Stack;

class MyQueue{
    Stack<Integer> st = new Stack<>();
    Stack<Integer> helper = new Stack<>();
    public void add(int val){
        st.push(val);
    }
    public int remove(){
        while(st.size() > 1){
            helper.push(st.pop());
        }
        int a = st.pop();
        while(helper.size() != 0){
            st.push(helper.pop());
        }
        return a;
    }
    public int peek(){
        while(st.size() > 1){
            helper.push(st.pop());
        }
        int a = st.peek();
        while(helper.size() != 0){
            st.push(helper.pop());
        }
        return a;
    }
    public boolean isEmpty(){
        return st.isEmpty();
    }
}

// pop efficient code
/*
 * class MyQueue {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> helper = new Stack<>();

    public MyQueue() {
        
    }
    
    public void push(int x) {
        
        while(st.size() != 0){
            helper.push(st.pop());
        }
        st.push(x);
        while(helper.size() != 0){
            st.push(helper.pop());
        }
    }
    
    public int pop() {
        return st.pop();
    }
    
    public int peek() {
        return st.peek();
    }
    
    public boolean empty() {
        return st.isEmpty();
    }
}
 */

public class ImplementQueueByStack {
    public static void main(String[] args) {
        
    }
}
