import java.util.Comparator;
import java.util.PriorityQueue;

public class KthLargestElementInArray {
    public static int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < nums.length; i++) q.add(nums[i]);
        for(int i = 0; i < k - 1; i++) q.remove();
        return q.peek();
    }
    public static void main(String[] args) {
        int[] nums = {3,7,2,9,5};
        System.out.println(findKthLargest(nums,3));
    }
}
