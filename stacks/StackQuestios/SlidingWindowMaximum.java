package StackQuestios;

import java.util.Stack;

/*
  You are given an array of integers nums, there is a sliding window of size k which is moving from the 
  very left of the array to the very right. You can only see the k numbers in the window. Each time the 
  sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


 */
public class SlidingWindowMaximum {
    // method 1 time complexity --> O(k*n)
    public static int[] maxWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int z = 0;
        for (int i = 0; i < n - k + 1; i++) { // loop run n-k+1 times
            int max = Integer.MIN_VALUE;
            for (int j = i; j < i + k; j++) { // loops runs k times
                max = Math.max(max, nums[j]);
            }
            ans[z++] = max;
        }
        return ans;
    }

    // method 2 using next greater element
    public static int[] maxWindow2(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int z = 0;
        
        Stack<Integer> st = new Stack<>();
        int [] nge = new int[n];
        st.push(n-1);
        nge[n-1] = n;
        for(int i = n-2; i >= 0; i--){
            while(st.size() > 0 && nums[st.peek()] < nums[i]){
                st.pop(); 
            }
            if(st.size() == 0) nge[i] = n;
            else nge[i] = st.peek();
            st.push(i);
        }
        for(int i = 0; i < n - k + 1; i++){
            // int max = Integer.MIN_VALU;
            int j = i;
            int max = nums[j];
            while(j < i + k){
                max = nums[j];
                j = nge[j];
            }
            ans[z++] = max;
        }
        return ans;
    }

    // method 3 fully optimised to O(n) 
    public static int[] maxWindow3(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n - k + 1];
        int z = 0;
        
        Stack<Integer> st = new Stack<>();
        int [] nge = new int[n];
        st.push(n-1);
        nge[n-1] = n;
        for(int i = n-2; i >= 0; i--){
            while(st.size() > 0 && nums[st.peek()] < nums[i]){
                st.pop(); 
            }
            if(st.size() == 0) nge[i] = n;
            else nge[i] = st.peek();
            st.push(i);
        }
        int j = 0;
        for(int i = 0; i < n - k + 1; i++){
            // int max = Integer.MIN_VALU;
            // int j = i;
            if(j >= i + k) j = i;
            int max = nums[j];
            while(j < i + k){
                max = nums[j];
                j = nge[j];
            }
            ans[z++] = max;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int k = 3;
        int[] arr = maxWindow3(nums, k);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
