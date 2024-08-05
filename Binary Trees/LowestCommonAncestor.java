

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
two nodes p and q as the lowest node in T that has both p and q as descendants
(where we allow a node to be a descendant of itself).”

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 */

public class LowestCommonAncestor {
    private static class Node{
        int data;
        Node left;
        Node right;
        public Node(int data){
            this.data = data;
        }
    }
    static Node ans = new Node(-1);
    public static boolean isContains(Node root,Node a){
        if(root == null) return false;
        if(root == a) return true;
        return isContains(root.left,a) || isContains(root.right,a);
    }
//    public static void helper(Node root,Node p,Node q,Node ans){
//        if(root == null) return;
//        if(isContains(root.left,p) && isContains(root.right,q)) ans = root;
//        if(isContains(root.left,q) && isContains(root.right,p)) ans = root;
//        if(isContains(root.left,p) && isContains(root.left,q)) helper(root.left,p,q,ans);
//        else helper(root.right,p,q,ans);
//    }
    public static Node lowestCommonAncestor(Node root,Node p,Node q){
        if(p == root || q == root) return root;
        if(p == q) return p;
        boolean leftP = isContains(root.left,p);
        boolean rightQ = isContains(root.right,q);
        if((leftP && rightQ) || (!leftP && !rightQ)) return root;
        if(leftP && !rightQ) return lowestCommonAncestor(root.left, p, q); // both are in left
        return lowestCommonAncestor(root.right, p, q); // both are in right
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
//        Node l = new Node(12);
//        System.out.println(isContains(root,l));
        System.out.println(lowestCommonAncestor(root,c,d).data);

    }
}
