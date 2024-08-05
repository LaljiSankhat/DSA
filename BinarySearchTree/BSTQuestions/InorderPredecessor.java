package BSTQuestions;

import java.util.ArrayList;
import java.util.List;

public class InorderPredecessor {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    static int pred = -1;
    static int suc = -1;
    static Node temp = null;
    static boolean flag = false;
    public static void inorder(Node root, List<Node> l){
        if(root == null) return;
        inorder(root.left,l);
        l.add(root);
        inorder(root.right,l);
    }
    public static int binarySearchInBST(List<Node> l,int target){
        int left = 0;
        int right = l.size();
        int mid = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(l.get(mid).val > target){
                right = mid - 1;
            }
            else if(l.get(mid).val < target){
                left = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
    public static void inorderPredAndSuc(Node root,int target){
        List<Node> l = new ArrayList<>();
        inorder(root,l);
        int idx = binarySearchInBST(l,target);
        System.out.println("Inorder predecessor is "+ l.get(idx - 1).val);
        System.out.println("Inorder successor is "+ l.get(idx + 1).val);
    }

    // method 2
    public static void inorderPredSuc(Node root,int target){
        if(root == null) return;
        inorderPredSuc(root.left,target);
        // kya kaam karana hain
        if(temp == null) temp = root;
        else{
            if(root.val == target) {
                pred = temp.val;
                flag = true;
            }
            else if(root.val > target && flag) {
                suc = root.val;
                flag = false;
            }
            else temp = root;
        }
        inorderPredSuc(root.right,target);
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        Node a = new Node(2);
        Node b = new Node(6);
        root.right = b;
        root.left = a;
        Node c = new Node(1);
        Node d = new Node(3);
        a.left = c;
        a.right = d;
        Node e = new Node(5);
        Node f = new Node(7);
        b.left = e;
        b.right = f;
        inorderPredAndSuc(root,3);
        int val = 5;
        inorderPredSuc(root,val);
        System.out.println(pred);
        System.out.println(suc);
    }
}
