import java.util.Stack;

public class BasicsOfStacks {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(5);
        st.push(4);
        st.push(1);
        st.push(8);
        st.push(4);
        st.push(56);
        System.out.println(st);
        st.pop();
        System.out.println(st);
        System.out.println(st.peek());
        System.out.println("Size of Stack is "+ st.size());
    }
}
