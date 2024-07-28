import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class TraversalsOfGT {
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
    public static void preorderTraversal(Node root){
        if(root.child.isEmpty()) {
            System.out.print(root.val+ " ");
            return;
        }
        System.out.print(root.val+" ");
        int n = root.child.size();
        for(int i = 0; i < n; i++){
            preorderTraversal(root.child.get(i));
        }
    }
    public static void postorderTraversal(Node root){
        if(root.child.isEmpty()){
            System.out.print(root.val+" ");
            return;
        }
        int n = root.child.size();
        for(int i = 0; i < n; i++){
            postorderTraversal(root.child.get(i));
        }
        System.out.print(root.val+" ");
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
//    public static void zigzagTraversal(Node root){
//        if(root == null) return;
//        Queue<Node> q = new LinkedList<>();
//        q.add(root);
//        int i = 1;
//        while(q.size() > 0){
//            Node temp = q.poll();
//            if(i % 2 != 0){
//                System.out.print(temp.val+" ");
//                int n = temp.child.size();
//                for(int j = n-1; j >=0; j--){
//                    q.add(temp.child.get(j));
//                }
//                i++;
//            }
//            else {
//                System.out.print(temp.val+" ");
//                int n = temp.child.size();
//                for(int j = 0; j < n; j++){
//                    q.add(temp.child.get(j));
//                }
//                i++;
//            }
//        }
//    }

    public static void zigzagTraversal (Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        int i = 1;
        while (q.size() > 0) {
            int levelSize = q.size();
            List<Node> currentLevel = new ArrayList<>();
            while (levelSize-- > 0) {
                Node currentNode = q.poll();
                currentLevel.add(currentNode);
                int n = currentNode.child.size();
                for (int j = 0; j < n; j++) {
                    q.add(currentNode.child.get(j));
                }
            }
            if (i % 2 != 0) {
                for (int j = 0; j < currentLevel.size(); j++) {
                    System.out.print(currentLevel.get(j).val + " ");
                }
            } else {
                for (int j = currentLevel.size() - 1; j >= 0; j--) {
                    System.out.print(currentLevel.get(j).val + " ");
                }
            }
            System.out.println();
            i++;
        }
    }
    public static int findMax(Node root){
        if(root.child.isEmpty()) return root.val;
        int max = root.val;
        for(int i = 0; i < root.child.size(); i++){
            int a = findMax(root.child.get(i));
            if(a > max) max = a;
        }
        return max;
    }

    public static void main(String[] args) {
        Node root = new Node(30);
        formGT(root);
        preorderTraversal(root);
        System.out.println();
        postorderTraversal(root);
        System.out.println();
        bfs(root);
        System.out.println();
        zigzagTraversal(root);
        System.out.println(findMax(root));
    }
}
