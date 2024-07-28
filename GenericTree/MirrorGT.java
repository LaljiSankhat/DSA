import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.util.Collections.reverse;

public class MirrorGT {
    public static class Node{
        int val;
        List<Node> child;
        public Node(int val){
            this.val = val;
            child = new ArrayList<>();
        }
    }
    public static void formGT(Node root){
        root.child.add(new Node(5));
        root.child.add(new Node(11));
        root.child.add(new Node(63));
        root.child.get(0).child.add(new Node(1));
        root.child.get(0).child.add(new Node(4));
        root.child.get(0).child.add(new Node(8));
        root.child.get(1).child.add(new Node(6));
        root.child.get(1).child.add(new Node(7));
        root.child.get(1).child.add(new Node(15));
        root.child.get(2).child.add(new Node(31));
        root.child.get(2).child.add(new Node(55));
        root.child.get(2).child.add(new Node(65));
    }
    public static void bfs(Node root){
        if(root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(q.size() > 0){
            Node temp = q.poll();
            System.out.print(temp.val+" ");
            int n = temp.child.size();
            for(int i = 0; i < n; i++){
                q.add(temp.child.get(i));
            }
        }
    }
    private static void reverseList(List<Node> l){
        int n = l.size()/2;
        for(int i = 0; i < n; i++){
            Node temp = l.get(n-1-i);
            l.set(n-1-i,l.get(i));
            l.set(i,temp);
        }
    }
    public static void mirrorGT(Node root){
        if(root.child.isEmpty()) return;
        int n = root.child.size();
        if(n == 1) return;
        reverse(root.child);
        for(int i = 0; i < root.child.size(); i++){
            mirrorGT(root.child.get(i));
        }
    }
    public static void main(String[] args) {
        Node root = new Node(30);
        formGT(root);
        bfs(root);
        System.out.println();
        mirrorGT(root);
        bfs(root);
    }
}
