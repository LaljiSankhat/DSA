import java.util.Stack;

public class UnderflowOverflow {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        // Underflow = empty Stack
        st.push(1);
        st.push(2);
        st.push(3);
        System.out.println(st);
        st.pop();
        System.out.println(st);
        st.pop();
        System.out.println(st);
        st.pop();

        st.pop();// this line give error because stack is empty or underflow

        // Overflow = when size of stack is fixed then if we want to push
        // element greater than size then stack is overflow.
    }
}
