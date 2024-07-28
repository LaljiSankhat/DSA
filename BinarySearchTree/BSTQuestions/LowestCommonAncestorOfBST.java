package BSTQuestions;

import java.security.PublicKey;

class Node{
    int val;
    Node left;
    Node right;
    public Node(int val){
        this.val = val;
    }
}
public class LowestCommonAncestorOfBST {
    public static Node lowestCommonAncestor(Node root,Node p,Node q){
        if(p == root || q == root) return root;
        if(p == q) return p;
        if(p.val < root.val && q.val < root.val){
            return lowestCommonAncestor(root.left,p,q);
        }
        else if(p.val > root.val && q.val > root.val){
            return lowestCommonAncestor(root.right,p,q);
        }
        else return root;
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
        System.out.println(lowestCommonAncestor(root,c,d).val);
    }
}
