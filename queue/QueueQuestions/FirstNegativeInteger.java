package QueueQuestions;

import java.util.LinkedList;
import java.util.Queue;

// First negative integer in every window of size k
/*
 * Given an array A[] of size N and a positive integer K, find the first negative integer 
 * for each and every window(contiguous subarray) of size K.
 * 
 * Input : 
  N = 5
  A[] = {-8, 2, 3, -6, 10}
  K = 2
  Output : 
  -8 0 -6 -6
  Explanation :
  First negative integer for each window of size k
  {-8, 2} = -8
  {2, 3} = 0 (does not contain a negative integer)
  {3, -6} = -6
  {-6, 10} = -6
 */
public class FirstNegativeInteger {
    public static int[] printFirstNegativeInteger(int[] a, int n, int k) {
        int[] res = new int[n - k + 1];
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                q.add(i);
            }
        }
        for (int i = 0; i < n - k + 1; i++) {
            if (q.size() > 0 && q.peek() < i)
                q.remove();
            if (q.size() > 0 && q.peek() <= i + k - 1) {
                res[i] = a[q.peek()];
            }
            else if (q.size() == 0)
                res[i] = 0;
            else
                res[i] = 0;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] a = {-8, 2, 3, -6, 10};
        int n = a.length;
        int k = 2;
        int [] temp = printFirstNegativeInteger(a, n, k);
        for(int i : temp){
            System.out.print(i+" ");
        }

    }
}
