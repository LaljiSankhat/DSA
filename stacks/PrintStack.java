import java.util.Stack;

public class PrintStack {

    // print recursively
    public static void displayRec(Stack<Integer> st){
        if(st.isEmpty()) return;
        int x = st.pop();
        displayRec(st);
        System.out.print(x+" ");
        st.push(x);

    }
    public static void displayReverseRec(Stack<Integer> st){
        if(st.isEmpty()) return;
        int x = st.pop();
        System.out.print(x+" ");
        displayReverseRec(st);
        st.push(x);
    }
    public static void main(String[] args) {
        Stack <Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println(st);

        // using Another stack
        // Stack<Integer> temp = new Stack<>();
//        while(st.size() > 0){
//            temp.push(st.pop());
//        }
//        while(temp.size() > 0){
//            int x = temp.pop();
//            st.push(x);
//            System.out.print(x+" ");
//        }


        // Using
        int n = st.size(),i;
        int [] arr = new int[n];
        for(i = n-1; i >= 0; i--){
            arr[i] = st.pop();
        }
        for(i = 0; i < n; i++){
            System.out.print(arr[i]+" ");
            st.push(arr[i]);
        }
        System.out.println();
        System.out.println(st);
        displayRec(st);
        System.out.println();
        displayReverseRec(st);
    }
}
