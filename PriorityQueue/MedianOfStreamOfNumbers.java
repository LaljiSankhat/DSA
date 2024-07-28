import java.util.Comparator;
import java.util.PriorityQueue;

public class MedianOfStreamOfNumbers {
    public static void add(int num, PriorityQueue<Integer> left, PriorityQueue<Integer> right) {
        if (left.isEmpty()) {
            left.add(num);
            return;
        }
//        if(right.isEmpty()){
//            if(num > left.peek()) right.add(num);
//            else {
//                right.add(left.remove());
//                left.add(num);
//            }
//            return;
//        }
//        else if(right.isEmpty()) right.add(num);
//        int leftMaximum = left.peek();
//        int rightMinimum = right.peek();
        // if num go to right
        if (num > left.peek()) {
            if (left.size() == right.size()) {
                right.add(num);
                left.add(right.remove());
            } else right.add(num);
        }
        else { // num go to left
            if (left.size() == right.size()) {
                left.add(num);
            } else {
                left.add(num);
                right.add(left.remove());
            }
        }

    }

    public static float finMedian(PriorityQueue<Integer> left, PriorityQueue<Integer> right) {
        if(right.isEmpty() && left.isEmpty()) return -1;
        if(left.size() - right.size() == 1){
            return left.peek();
        }
        return (left.peek() + right.peek()) / 2f;
    }

    public static void main(String[] args) {
        PriorityQueue<Integer> left = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> right = new PriorityQueue<>();
//         1 : 45 :00
        add(15,left,right);
        System.out.println(finMedian(left,right));
        add(10,left,right);
        System.out.println(finMedian(left,right));
        add(5,left,right);
        System.out.println(finMedian(left,right));
        add(20,left,right);
        System.out.println(finMedian(left,right));
        add(25,left,right);
        System.out.println(finMedian(left,right));

    }
}

/*
 // better solution

 private PriorityQueue<Integer> small = new PriorityQueue<>(Collections.reverseOrder());
private PriorityQueue<Integer> large = new PriorityQueue<>();
private boolean even = true;

public double findMedian() {
    if (even)
        return (small.peek() + large.peek()) / 2.0;
    else
        return small.peek();
}

public void addNum(int num) {
    if (even) {
        large.offer(num);
        small.offer(large.poll());
    } else {
        small.offer(num);
        large.offer(small.poll());
    }
    even = !even;
}
 */
/* // my solution
 class MedianFinder {
    PriorityQueue<Integer> numbers = new PriorityQueue<>();
    public MedianFinder() {

    }

    public void addNum(int num) {
        numbers.add(num);
    }

    public double findMedian() {
        PriorityQueue<Integer> median = new PriorityQueue<>(numbers);
        int n = median.size();
        int prev = 0;
        for(int i = 0; i < (n / 2); i++) {
            prev = median.remove();
        }
        if(n % 2 == 0){
            return (prev + median.peek()) / 2f;
        }
        return median.peek();
    }
}

 */
