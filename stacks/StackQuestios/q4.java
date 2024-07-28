package StackQuestios;


import java.util.Stack;

// remove consecutive subsequences means remove all elements which repeats consecutively
public class q4 {
    public static int[] remove(int [] arr){
        Stack<Integer> st = new Stack<>();
        // int b = -1;
        for(int i = 0;i< arr.length;i++){
            int a = arr[i];
            if(st.isEmpty() || (a != st.peek())){
                st.push(a);
                continue;
            }
            if(a == st.peek()){
               if(i+1 > arr.length - 1  || arr[i] != arr[i+1]) st.pop();
            }
        }
        int[] result = new int[st.size()];
        int m = result.length;
        for(int j = m-1;j>=0;j--){
            result[j] = st.pop();
        }
        return result;
    }
    public static void main(String[] args) {
        int [] arr = {1,2,2,3,10,10,10,10,4,4,4,5,7,7,2};
        int [] a = remove(arr);
        for (int j : a) {
            System.out.print(j + " ");
        }
    }
}
