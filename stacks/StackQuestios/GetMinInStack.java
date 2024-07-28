package StackQuestios;



// Create a function name getMin() which will return minimum value of stack At any instance
// in O(1) time complexity   O(n) : space complexity

// leetCode solution
/*
class MinStack {
    Stack<Integer> st = new Stack<>();
    Stack<Integer> min = new Stack<>();
    public MinStack() {

    }

    public void push(int val) {
        if(st.size() == 0){
            st.push(val);
            min.push(val);
        }
        else{
            st.push(val);
            if(val < min.peek()){
               min.push(val);
            }
            else{
                min.push(min.peek());
            }
        }
    }

    public void pop() {
        st.pop();
        min.pop();
    }

    public int top() {
        return st.peek();
    }

    public int getMin() {
        return min.peek();
    }
}


 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();

 */

import java.util.Stack;

// Without using extra stack
class MinStack{
    int min;
    Stack<Integer> st = new Stack<>();
    public void push(int val){
        if(st.size() == 0){
            st.push(val);
            min = val;
        }
        else{
            if(min > val){
                st.push(2*val-min);
                min = val;
            }else{
                st.push(val);
            }
        }
    }
    public void pop(){
        if(st.size() == 0) return;
        if(st.peek() < min){
            min = 2*min - st.peek();
            st.pop();
        }else{
            st.pop();
        }
    }
    public int top(){
        if(st.size() == 0) return -1;
        if(st.peek() < min){
            return min;
        }
        return st.peek();
    }

    public int getMin(){
        if(st.size() == 0) return -1;
        return min;
    }
}
public class GetMinInStack {
    public static void main(String[] args) {
        MinStack m = new MinStack();
//        m.push(7);
//        m.push(8);
//        m.push(5);
//        m.push(6);
//        m.push(3);
//        m.push(4);
//        System.out.println(m.getMin());
//        m.pop();
//        System.out.println(m.getMin());
//        System.out.println(m.top());
//        m.pop();
//        System.out.println(m.peek());
//        System.out.println(m.getMin());
//        m.pop();
//        System.out.println(m.getMin());
//        m.pop();
//        System.out.println(m.getMin());
//        m.pop();
        m.push(2);
        m.push(0);
        m.push(3);
        m.push(0);
        m.pop();
        m.pop();
        System.out.println(m.getMin());
        m.pop();
        System.out.println(m.getMin());

    }
}
