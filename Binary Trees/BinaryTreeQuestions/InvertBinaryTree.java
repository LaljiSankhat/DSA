package BinaryTreeQuestions;

/*
Given the root of a binary tree, invert the tree, and return its root.

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Input: root = [2,1,3]
Output: [2,3,1]

Input: root = []
Output: []
 */

class Node{
    int val;
    Node right;
    Node left;
    public Node(int val){
        this.val = val;
    }
}
public class InvertBinaryTree {
    public static Node invertTree(Node root){
        if(root == null || (root.right == null && root.left == null)) return root;
        Node temp = invertTree(root.left);
        Node temp2 = invertTree(root.right);
        root.left = temp2;
        root.right = temp;
        return root;
    }
    public static void display(Node root){
        if(root == null) return;
        System.out.print(root.val+" -> ");
        if(root.left != null) System.out.print(root.left.val+",");
        else System.out.print("null ");
        if(root.right != null) System.out.print(root.right.val+" ");
        else System.out.print("null ");
        System.out.println();
        if(root.left != null) display(root.left);
        if(root.right != null) display(root.right);
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
        display(root);
        Node t = invertTree(root);
        System.out.println();
        display(t);
    }
}
