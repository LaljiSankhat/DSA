
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
 */

public class DiameterOfBinaryTree {
    public static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public static int diameterOfBinaryTree(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        int leftAns = diameterOfBinaryTree(root.left);
        int rightAns = diameterOfBinaryTree(root.right);
        int mid = height(root.left) + height(root.right);
        if(root.left != null) mid++;
        if(root.right != null) mid++;
        return Math.max(leftAns,Math.max(rightAns,mid));
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
        System.out.println(diameterOfBinaryTree(root));
    }
}
