package BinaryTreeQuestions;


/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]
Output: true
Input: root = [1,2,2,null,3,null,3]
Output: false
 */
public class SymmetricBinaryTree {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static Node invertTree(Node root){
        if(root == null || (root.right == null && root.left == null)) return root;
        Node temp = invertTree(root.left);
        Node temp2 = invertTree(root.right);
        root.left = temp2;
        root.right = temp;
        return root;
    }
    public static boolean isSameTree(Node p, Node q) {
        if(q == null && p == null) return true;
        if(q == null || p == null) return false;
        if(p.val != q.val) return false;
        return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
    }
    public static boolean isSymmetric(Node root){
        if(root == null) return true;
        Node rightNode = root.right;
        Node leftNode = invertTree(root.left);
        return isSameTree(leftNode,rightNode);
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
        System.out.println(isSymmetric(root));
        System.out.println(isSymmetric(null));
    }
}
