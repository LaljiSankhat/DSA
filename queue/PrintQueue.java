import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class PrintQueue {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
        System.out.println(q);
        Queue<Integer> t = new ArrayDeque<>();
        while(q.size() != 0){
            t.add(q.peek());
            q.remove();
        }
        System.out.println(t);
        while(t.size() != 0){
            int a = t.peek();
            t.remove();
            q.add(a);
            System.out.print(a+" ");
        }
    }
}
