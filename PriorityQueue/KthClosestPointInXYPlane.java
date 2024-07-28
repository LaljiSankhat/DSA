import java.awt.*;
import java.util.*;
import java.util.List;

public class KthClosestPointInXYPlane {
    public static class point{
        int x;
        int y;

        public point(int x,int y){
            this.x = x;
            this.y = y;
        }
        int distance = (x * x) + (y * y);
    }
    public static class pointComparator implements Comparator<point>{
        public int compare(point p1,point p2){
            if(p1.distance < p2.distance) return 1;
            else if(p1.distance > p2.distance) return -1;
            else return 0;
        }
    }
//    public static void KthSmallestDistance(List<point> a,int k){
//        PriorityQueue<point> pt = new PriorityQueue<>(new pointComparator());
//        for(int i = 0; i < a.size(); i++) pt.add(a.get(i));
//        for(int i = 0; i < k -1; i++) pt.remove();
//        System.out.print(pt.peek().x+" ");
//        System.out.print(pt.peek().y+" ");

    public static int KthSmallestDistance(List<point> a,int k){
        PriorityQueue<Integer> pt = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < a.size(); i++) pt.add(a.get(i).distance);
        for(int i = 0; i < k -1; i++) pt.remove();
        return pt.peek();
    }
    public static void main(String[] args) {
//        int[][] points = {{5,3},
//                          {1,2},
//                          {3,4},
//                          }
        point p1 = new point(1,2);
        point p2 = new point(5,3);
        point p3 = new point(3,4);
        point p4 = new point(5,6);
        point p5 = new point(7,8);
        List<point> p = new ArrayList<>();
        HashMap<Integer,point> mp = new HashMap<>();
        p.add(p1);
        p.add(p2);
        p.add(p3);
        p.add(p4);
        p.add(p5);
        for(int i = 0; i < p.size(); i++){
            mp.put(p.get(i).distance,p.get(i));
        }
        int key = KthSmallestDistance(p,3);
        System.out.print(mp.get(key).x+" ");
        System.out.print(mp.get(key).y+" ");
    }
}
