import java.util.Stack;

public class ReverseStack {
    public static void insertBottom(Stack<Integer> st,int val){
        if(st.size() == 0) {
            st.push(val);
            return;
        }
        int x = st.pop();
        insertBottom(st,val);
        st.push(x);
    }
    // Reverse stack recursively
    public static void reverseStack(Stack<Integer> st){
        if(st.size() == 1) return;
        int x = st.pop();
        reverseStack(st);
        insertBottom(st,x);
    }
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println(st);
        reverseStack(st);
        System.out.println(st);
    }
}
