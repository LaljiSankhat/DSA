class Stack{
    private int [] arr = new int[4];
    private int idx = 0;
    int n = arr.length;
    void push(int x){
        if(isFull()){
            System.out.println("Stack overflow");
            return;
        }
        arr[idx++] = x;
    }
    int peek(){
        if(idx == 0){
            System.out.println("Stack is empty");
            return -1;
        }
        return arr[idx - 1];
    }
    int pop(){
        if(idx == 0){
            System.out.println("Stack is empty");
            return -1;
        }
        int top = arr[idx - 1];
        arr[idx - 1] = 0;
        idx--;
        return top;
    }
    void display(){
        for(int i = 0;i<idx;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    int size(){
        return idx;
    }
    boolean isEmpty(){
        if(idx == 0) return true;
        return false;
    }
    boolean isFull(){
        return idx == n;
    }
    int capacity(){
        return n;
    }
}


public class ArrayImplementationOfStack {
    public static void main(String[] args) {
        Stack st = new Stack();
        System.out.println(st.capacity());
        st.push(4);
        st.display();
        st.push(5);
        st.display();
        st.push(2);
        st.display();
        st.push(8);
        st.display();
        System.out.println(st.size());
//        st.pop();
//        st.display();
        System.out.println(st.isFull());
        st.push(4);
    }
}
