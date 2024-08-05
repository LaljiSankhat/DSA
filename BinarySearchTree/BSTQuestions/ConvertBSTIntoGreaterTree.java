package BSTQuestions;


/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key
of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
As a reminder, a binary search tree is a tree that satisfies these constraints:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Input: root = [0,null,1]
Output: [1,null,1]

 */
public class ConvertBSTIntoGreaterTree {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static void inorder(Node root){
        if(root == null) return;
        inorder(root.right);
        System.out.print(root.val+" ");
        inorder(root.left);
    }
    static Node temp = new Node(0);
    public static void changeValues(Node root){
        if(root == null) return;
        changeValues(root.right);
        root.val += temp.val;
        temp = root;
        changeValues(root.left);
    }

    public static Node convertBST(Node root){
        changeValues(root);
        return root;
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
        Node t = convertBST(root);
        inorder(root);
    }
}
