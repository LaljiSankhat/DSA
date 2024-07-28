import java.util.Stack;

public class Insetion {

    // Insert at bottom using recursion
    public static void insertBottom(Stack<Integer> st,int val){
        if(st.size() == 0){
            st.push(val);
            return;
        }
        int x = st.pop();
        insertBottom(st,val);
        st.push(x);
    }

    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        // to insert 10 at second(2) position
        Stack<Integer> temp = new Stack<>();
        int index = 0;
        while (st.size() > index){
            temp.push(st.pop());
        }
        st.push(10);
        while(temp.size() > 0){
            st.push(temp.pop());
        }
        System.out.println(st);
        insertBottom(st,39);
        System.out.println(st);
    }
}
