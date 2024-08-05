package BinaryTreeQuestions;


/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer
points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
 */
public class FlattenBinaryTreeToLinkedList {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
//    public static Node flatten(Node root){
//        if(root.left == null && root.right == null) return root;
//        Node temp = root;
//        root.left = null;
//        if(temp.left != null) {
//            root.right = flatten(temp.left);
//            root = root.right;
//        }
//        if(root.right != null) {
//            root.right = flatten(temp.right);
//        }
//    }
    public static Node flatten(Node root){
        if(root.left == null && root.right == null) return root;
        Node left = flatten(root.left);
        Node right = flatten(root.right);
        root.right = left;
        while(left.right != null) left = left.right;
        left.right = right;
        root.left = null;
        return root;
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
        Node temp = flatten(root);
        while(temp != null){
            System.out.print(temp.val+" ");
            temp = temp.right;
        }
    }
}

/*
 // leetcode

 class Solution {
    public void flatten(TreeNode root) {
        if(root == null) return;
        if(root.left == null && root.right == null) return;
        TreeNode left = root.left;
        TreeNode right = root.right;
        flatten(root.left);
        flatten(root.right);
        root.right = left;
        TreeNode temp = left;
        while(temp != null && temp.right != null) temp = temp.right;
        if(temp != null) temp.right = right;
        else root.right = right;
        root.left = null;
        return;
    }
}
 */
