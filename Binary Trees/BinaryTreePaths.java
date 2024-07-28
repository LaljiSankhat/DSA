
/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
 */

import java.util.ArrayList;
import java.util.List;

public class BinaryTreePaths {
    private static class  Node {
        int val;
        Node left;
        Node right;
        public Node(int data){
            this.val = data;
        }
    }
    public static void helper(Node root,List<String> l,String s){
        if(root == null) {
            return;
        }
        if(root.left == null && root.right == null){
            s += root.val;
            l.add(s);
//            s = s.substring(0,s.length()-2);
            return;
        }
        helper(root.left,l,s+root.val+"->");
        helper(root.right,l,s+root.val+"->");
    }
    public static List<String> binaryTreePath(Node root){
        List<String> l = new ArrayList<>();
        helper(root,l,"");
        return l;
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
        System.out.println(binaryTreePath(root));

    }
}
