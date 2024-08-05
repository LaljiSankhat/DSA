package BinaryTreeQuestions;


import java.util.*;

/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 (i.e., from left to right, then right to left for the next level and alternate between).

 Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
 */
public class ZigzagLevelOrderTraversal {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public static void nThLevel(Node root,int n,List<Integer> l){
        if(root == null) return;
        if(n == 1){
            l.add(root.val);
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1,l);
        nThLevel(root.right,n-1,l);
    }
    public static void nThLevelReverse(Node root,int n,List<Integer> l){
        if(root == null) return;
        if(n == 1){
            l.add(root.val);
            return;
        }
        // preorder root left right calls
        nThLevelReverse(root.right,n-1,l);
        nThLevelReverse(root.left,n-1,l);
    }
    public static List<List<Integer>> zigzagLevelOrder(Node root){
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        int level = 1 + height(root);
        for(int i = 1; i <= level; i++){
            List<Integer> a = new ArrayList<>();
            if(i % 2 != 0){
                nThLevel(root,i,a);
                ans.add(a);
            }
            else{
                nThLevelReverse(root,i,a);
                ans.add(a);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Node root = new Node(1);
        Node a = new Node(2);
        Node b = new Node(3);
        root.right = b;
        root.left = a;
        Node c = new Node(4);
        Node d = new Node(5);
        a.left = c;
        a.right = d;
        Node e = new Node(6);
        Node f = new Node(7);
        b.left = e;
        b.right = f;
        List<List<Integer>> ans = zigzagLevelOrder(root);
        System.out.println(ans);

    }
}

// simple level order traversal not zigzag
/*
class Solution {
    public int height(TreeNode root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public void nThLevel(TreeNode root,int n,List<Integer> l){
        if(root == null) return;
        if(n == 1){
            l.add(root.val);
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1,l);
        nThLevel(root.right,n-1,l);
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        List<Integer> l = new ArrayList<>();
        int level = height(root) + 1;
        for(int i = 1; i <= level; i++){
            List<Integer> a = new ArrayList<>();
            nThLevel(root,i,a);
            ans.add(a);
        }
        return ans;
    }
}
 */
