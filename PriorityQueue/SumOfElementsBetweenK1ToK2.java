import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class SumOfElementsBetweenK1ToK2 {
    public static int printSum(List<Integer> arr,int k1,int k2){
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < arr.size(); i++){
            pq.add(arr.get(i));
            if(pq.size() > k2) pq.remove();
        }
        pq.remove(); // removed k2th element
        int sum = 0;
        while(pq.size() != k1) {
            sum += pq.remove();
        }
        return sum;
    }
    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(20);
        arr.add(8);
        arr.add(22);
        arr.add(4);
        arr.add(12);
        arr.add(10);
        arr.add(14);
        int k1 = 3;
        int k2 = 6;
        System.out.println(printSum(arr,3,6));
//        1 : 27 : 00
    }
}
