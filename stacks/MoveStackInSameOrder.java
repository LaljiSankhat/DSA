// import java.util.Scanner;
import java.util.Stack;

public class MoveStackInSameOrder {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
//        int n;
//        System.out.println("Enter the number of elements of stack");
//        Scanner sc = new Scanner(System.in);
//        n = sc.nextInt();
//        System.out.println("Enter elements of stack");
//        for(int i = 0; i < n; i++){
//            int val = sc.nextInt();
//            st.push(val);
//        }
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println(st);
        Stack<Integer> st2 = new Stack<>();
        while(st.size() > 0){
//            st2.push(st.peek());
//            st.pop();

            // this is also written in one line
            st2.push(st.pop());
        }
        System.out.println(st2);
        System.out.println("Now original Stack is Empty "+st);

        // Now to copy in same order we use another stack
        Stack<Integer> copyStack = new Stack<>();
        while(st2.size() > 0){
            copyStack.push(st2.pop());
        }
        System.out.println(copyStack);
    }
}
