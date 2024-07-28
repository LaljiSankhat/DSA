package StackQuestios;


import java.util.Stack;

/*
Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in the histogram.


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

// leetcode answer
/*
    class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int n = heights.length;
        int [] pse = new int[n];
        int [] nse = new int[n];
        st.push(n-1);
        nse[n-1] = n;
        for(int i = n-2; i>=0; i--){
            while(st.size() > 0 && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            if(st.size() == 0) nse[i] = n;
            else{
                 nse[i] =  st.peek();
            }
            st.push(i);
        }

        while(st.size() > 0) st.pop();

        pse[0] = -1;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(st.size() > 0 && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            if(st.size() == 0) pse[i] = -1;
            else{
                pse[i] = st.peek();
            }
            st.push(i);
        }


        int max = -1;
        for(int i = 0; i< n; i++){
            int area = (heights[i])*(nse[i] - pse[i] -1);
            max = Math.max(max,area);
        }
        return max;
    }
}
 */

public class LargestRecInHistogram {
    static int[] nextSmallerElement(int[] arr){
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int[] nse = new int[n];
        nse[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){

            while(st.size() > 0 && arr[st.peek()] > arr[i]){
                st.pop();
            }
            if(st.size() == 0){
                nse[i] = n;
            }else{
                nse[i] = st.peek();
            }
            st.push(i);
        }
        return nse;
    }
    static int[] preSmallerElement(int [] arr){
        Stack<Integer> s = new Stack<>();
        int n = arr.length;
        int[] pse = new int[n];
        pse[0] = -1;
        s.push(0);
        for(int i = 1; i < n; i++){
            while(s.size() > 0 && arr[s.peek()] > arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                pse[i] = -1;
            }else{
                pse[i] = s.peek();
            }
            s.push(i);
        }
        return pse;
    }
    public static int maxArea(int[] arr){
        int max = -1;
        int [] pse = preSmallerElement(arr);
        int [] nse = nextSmallerElement(arr);
        for(int i = 0; i< arr.length; i++){
            int area = (arr[i])*(nse[i] - pse[i] -1);
            max = Math.max(max,area);
        }
        return max;
    }
    public static void main(String[] args) {
       int [] arr = {2,1,5,6,2,3};
//       int []res = preSmallerElement(arr);
//       for(int j : res){
//           System.out.print(j+ " ");
//       }
        int max = maxArea(arr);
        System.out.println(max);
    }
}
