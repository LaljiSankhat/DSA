// import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class BasicSTL {
    public static void main(String[] args) {
        // Queue<Integer> q = new ArrayDeque<>();
        Queue<Integer> q = new LinkedList<>();

        // operations 1.add, 2.remove, 3.peek, 4.size, 5.isEmpty
        System.out.println(q.isEmpty());
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        System.out.println(q);
        System.out.println(q.size());
        q.remove();
        System.out.println(q);
        q.poll();// as same as remove
        System.out.println(q);
        System.out.println(q.element());
        System.out.println(q.peek()); // peek and element are same
        // for size
        System.out.println(q.size());
    }
}
