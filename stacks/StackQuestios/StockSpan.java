package StackQuestios;


import java.util.Stack;

/*
The stock span problem is a financial problem where we have a series of N daily
price quotes for a stock and we need to calculate the span of the stock’s price for all N days.
 The span Si of the stock’s price on a given day i is defined as the maximum number of
  consecutive days just before the given day, for which the price of the stock on the current
   day is less than its price on the given day.

Examples:

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1,
60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on.
Hence the output will be 1 1 1 2 1 4 6.
* */
public class StockSpan {
//    public static void copyStack(Stack<Integer> a,Stack<Integer> b){
//        while(!a.isEmpty()){
//            b.push(a.pop());
//        }
//    }
    public static int[] stockSpan(int [] arr){
        int n = arr.length;
        int[] res = new int[n];
        Stack<Integer> st = new Stack<>();
        st.push(arr[0]);
        res[0] = 1;
        int count = 1;
        for(int i = 1; i < n; i++){
//            Stack<Integer> temp = new Stack<>();
//            copyStack(st,temp);
//            System.out.println(temp);

//            while(temp.size() > 0){
//                if(temp.peek() < arr[i]){
//                    count+=1;
//                    temp.pop();
//                }
//                else temp.pop();
//            }
//            res[i] = count;
//            st.push(arr[i]);
            while(st.size() > 0 && st.peek() < arr[i]){
                count++;
                st.pop();
            }
            st.push(arr[i]);
            res[i] = count;
        }
        return res;
    }
    public static void main(String[] args) {
          int [] arr = {10,80,70,60,70,80,85};
          int [] a = stockSpan(arr);
          for(int j : a){
              System.out.print(j+" ");
          }
    }
}
