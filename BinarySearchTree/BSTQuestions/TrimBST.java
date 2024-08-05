package BSTQuestions;


import java.util.ArrayList;
import java.util.List;

/* // leetcode 669
Given the root of a binary search tree and the lowest and highest boundaries as low and high,
trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change
the relative structure of the elements that will remain in the tree
(i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.
Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]

Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]
 */
public class TrimBST {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static void helper(Node root,int low,int high){
        if(root == null) return;
        while(root.left != null && (root.left.val < low || root.left.val > high)){ // trim
            if(root.left.val < low)  root.left = root.left.right;
            else root.left = root.left.left;
        }
        while(root.right != null && (root.right.val > high || root.right.val < low)){ // trim
            if(root.right.val > high) root.right = root.right.left;
            else root.right = root.right.right;
        }
        helper(root.left,low,high);
        helper(root.right,low,high);
    }
    public static Node trimBST(Node root,int low,int high){
        Node temp = new Node(Integer.MAX_VALUE);
        temp.left = root;
        helper(temp,low,high);
        return temp.left;
    }
    public static void inorder(Node root){
        if(root == null) return;
        inorder(root.left);
        System.out.print(root.val+" ");
        inorder(root.right);
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
        Node t = trimBST(root,3,5);
        inorder(t);
        // 46 : 55
    }
}
