package BinaryTreeQuestions;

import java.util.LinkedList;
import java.util.Queue;

public class BoundaryOfTree {
    public static Node constructTree(String[] arr){
        Queue<Node> q = new LinkedList<>();
        int first = Integer.parseInt(arr[0]);
        Node root = new Node(first);
        q.add(root);
        for(int i = 1; i < arr.length - 1; i = i+2){
            Node current = q.poll();
            if(!arr[i].equals("")){
                int num = Integer.parseInt(arr[i]);
                Node a = new Node(num);
                current.left = a;
                q.add(a);
            }
            if(!arr[i+1].equals("")){
                int nextNum = Integer.parseInt(arr[i+1]);
                Node a = new Node(nextNum);
                current.right = a;
                q.add(a);
            }
        }
        return root;
    }
    static void nThLevel(Node root, int n){
        if(root == null) return;
        if(n == 1){
            System.out.print(root.val+" ");
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1);
        nThLevel(root.right,n-1);
    }
    static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }

    public static void boundaryDisplay(Node root){
        leftBoundary(root);
        bottomBoundary(root);
        rightBoundary(root.right);
    }
    public static void leftBoundary(Node root){
        if(root == null || (root.left == null && root.right == null)) return;
        System.out.print(root.val+" ");
        if(root.left != null) leftBoundary(root.left);
        else leftBoundary(root.right);
    }
    public static void bottomBoundary(Node root){
        if(root == null) return;
        if(root.left == null && root.right == null){
            System.out.print(root.val+" ");
            return;
        }
        bottomBoundary(root.left);
        bottomBoundary(root.right);
    }
    public static void rightBoundary(Node root){
        if(root == null || (root.right == null && root.left == null)) return;
        if(root.right != null) rightBoundary(root.right);
        else rightBoundary(root.left);
        System.out.print(root.val+" ");
    }
    public static void main(String[] args) {
        String[] arr = {"1","2","3","4","5","","6","7","","8","","9","10","","11","","12","","13","","14","15","16","","17",
                        "","","18","","19","","","","20","21","22","23","","24","25","26","27","","","28","",""};
        Node root = constructTree(arr);
//        int level = height(root) + 1;
//        for(int i = 0; i <= level; i++){
//            nThLevel(root,i);
//            System.out.println();
//        }
        boundaryDisplay(root);


    }
}
