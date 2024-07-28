import java.util.Stack;

public class PopElement {
    // to remove element at index
    public static void removeAtIndex(Stack<Integer> st,int index){
        Stack<Integer> temp = new Stack<>();
        while(st.size() > index + 1){
            temp.push(st.pop());
        }
        st.pop();
        while(temp.size() > 0){
            st.push(temp.pop());
        }
    }
    public static void removeAtIndexRec(Stack<Integer> st,int index){
        if(st.size() == index + 1){
            st.pop();
            return;
        }
        int x = st.pop();
        removeAtIndexRec(st,index);
        st.push(x);
    }
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println(st);
        removeAtIndex(st,2);
        System.out.println(st);
        removeAtIndexRec(st,1);
        System.out.println(st);
    }
}
