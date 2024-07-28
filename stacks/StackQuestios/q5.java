package StackQuestios;


// next greater elements

import java.util.Stack;

public class q5 {
    //using only loops
    public static int[] nextGreater(int[] arr){
        int n = arr.length;
        int [] res = new int[n];
        for(int i = 0; i < n-1; i++){
            res[i] = -1;
            for(int j = i+1; j<n;j++){
                if(arr[j] > arr[i]){
                    res[i] = arr[j];
                    break;
                }
            }

        }
        return res;
    }
    // using stacks
    public static int[] nextGreaterElements(int [] arr){
        Stack<Integer> st1 = new Stack<>();
        int n = arr.length;
        int[] res = new int[n];
        st1.push(arr[n-1]);
        res[n-1] = -1;
        for(int i = n-2;i>= 0;i--){
                while(st1.size() > 0 && st1.peek() < arr[i]){
                    st1.pop();
                }
                if(st1.size() == 0) res[i] = -1;
                else res[i] = st1.peek();
                st1.push(arr[i]);
        }
        return  res;
    }

    // method 2
    public static void main(String[] args) {
        int [] arr = {1,5,3,2,1,6,3,4};
//        int[] b = nextGreater(arr);
        int [] c = nextGreaterElements(arr);
//        for(int j : b){
//            System.out.print(j+" ");
//        }
        for(int j : c){
            System.out.print(j+" ");
        }
    }
}
