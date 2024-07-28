import java.util.Comparator;
import java.util.PriorityQueue;

public class MultiplyKTimesOfMinElements {
    public static int multipliedAns(int[] arr,int k){
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int j = 0; j < arr.length; j++){
            pq.add(arr[j]);
        }
        int i = 1;
        while(i <= k){
            int num1 = pq.remove();
            int num2 = pq.remove();
            pq.add(num1 * num2);
            i++;
        }
//        PriorityQueue<Integer> pq2 = new PriorityQueue<>(Comparator.reverseOrder());
//        while(pq.size() > 0){
//            pq2.add(pq.remove());
//        }
        while(pq.size() != 1) pq.remove();
        return pq.peek();
    }
    public static void main(String[] args) {
        int[] arr = {2,4,3,1,5};
        int k = 3;
        System.out.println(multipliedAns(arr,k));
    }
}
